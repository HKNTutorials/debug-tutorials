default: all
LEVEL = .
include Makefile.inc

all: ${LIB}/CuTest.o ${ASSETS}/remark.min.js gdb-intro.html

${ASSETS}/remark.min.js:
	curl -o $@ http://gnab.github.io/remark/downloads/remark-0.5.3.min.js

SLIDES = slides/gdb-intro.md
SLIDES += exp/exp.md exp/exp-soln.md
SLIDES += square_ints/square_ints.md square_ints/square_ints-soln.md
TEMPLATE = slides/presentation.template.html

gdb-intro.html: ${SLIDES} ${TEMPLATE}
	${BIN}/combine-slides.py -m ${TEMPLATE} -t "GDB Intro" -o $@ ${SLIDES}
