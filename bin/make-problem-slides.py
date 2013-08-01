#!/usr/bin/env python
# vim: ts=4:sw=4:et

import pystache


def create_problem(template, problem, synopsis, extra_slides):
    info = {"problem": problem,
            "synopsis": synopsis,
            "extra_slides": extra_slides}
    return pystache.render(template, info)


import argparse
parser = argparse.ArgumentParser(description="Create a presentation HTML file")
parser.add_argument("-m", "--template", default="problem.template.md",
                    help="Template filename")
parser.add_argument("problem", help="name of problem")
parser.add_argument("-e", "--extra", default="extra_slides.md",
                    help="filename of additional slides")
parser.add_argument("-s", "--synopsis",
                    default="synopsis.h",
                    help="filename of synopsis")
parser.add_argument("-o", "--output", default="problem.md",
                    help="Output filename")
args = parser.parse_args()

info = {"problem": args.problem}
synopsis_file = pystache.render(args.synopsis, info)
extra_slides_file = pystache.render(args.extra, info)
output_file = pystache.render(args.output, info)

template = None
with open(args.template) as f:
    template = f.read()

extra_slides = None
with open(extra_slides_file) as f:
    extra_slides = f.read()

synopsis = None
with open(synopsis_file) as f:
    synopsis = f.read()

problem_md = create_problem(template,
                            args.problem,
                            synopsis,
                            extra_slides)
with open(output_file, "w") as f:
    f.write(problem_md)
