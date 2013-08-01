#!/usr/bin/env python
# vim:ts=4:sw=4

from __future__ import print_function

import subprocess

import signal
import sys

import argparse
parser = argparse.ArgumentParser(
    formatter_class=argparse.ArgumentDefaultsHelpFormatter)
parser.add_argument("-t", "--time",
                    default=5,
                    type=int,
                    help="timeout in seconds")
parser.add_argument("command", nargs="+", help="command and arguments to run")
args = parser.parse_args()

p = subprocess.Popen(args.command)

def cleanup_handler(signum, frame):
    print("Command terminated early")
    p.kill()
    sys.exit(127)

signal.signal(signal.SIGINT, cleanup_handler)

def handler(signum, frame):
    print("Command timed-out after %d seconds" % args.time)
    p.kill()
    sys.exit(128)

signal.signal(signal.SIGALRM, handler)
signal.alarm(args.time)

ret = p.wait()
sys.exit(ret)
