#!/usr/bin/env python

import pystache

def create_presentation(template, info, files):
  renderer = pystache.Renderer()
  slides = []
  for fname in files:
    with open(fname) as f:
      contents = f.read()
    slides.append({"contents": contents})
  info["slides"] = slides
  return renderer.render(template, info)

def main():
  import argparse
  parser = argparse.ArgumentParser(description = "Create a presentation HTML file")
  parser.add_argument("-m", "--template", default="presentation.template.html",
      help="Template filename")
  parser.add_argument("-o", "--output", default="presentation.html",
      help="Output filename")
  parser.add_argument("-t", "--title", help="Title of presentation")
  parser.add_argument("files", nargs="+", help="list of files with slides")
  args = parser.parse_args()
  loaded_template = None
  with open(args.template) as f:
    loaded_template = f.read()
  with open(args.output, "w") as f:
    html = create_presentation(loaded_template, {"title": args.title}, args.files)
    f.write(html)

if __name__ == "__main__":
  main()
