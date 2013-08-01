default: assets gdb-intro.html
LEVEL = .
include Makefile.inc

assets: ${LIB}/CuTest.o ${ASSETS}/remark.min.js

${ASSETS}/remark.min.js:
	curl -o $@ http://gnab.github.io/remark/downloads/remark-0.5.3.min.js

PROBLEMS := exp square_ints floating_point

SLIDES := slides/gdb-intro.md
PROBLEM_SLIDES := $(foreach prob,$(PROBLEMS),$(prob)/problem.md)
SOLN_SLIDES := $(foreach prob,$(PROBLEMS),$(prob)/soln.md)
SLIDES += $(PROBLEM_SLIDES) $(SOLN_SLIDES)

$(PROBLEM_SLIDES): %/problem.md:
	$(MAKE) -C $(dir $@) slides

TEMPLATE := slides/presentation.template.html
gdb-intro.html: slides ${SLIDES} ${TEMPLATE}
	${BIN}/combine-slides.py -m ${TEMPLATE} -t "GDB Intro" -o $@ ${SLIDES}
