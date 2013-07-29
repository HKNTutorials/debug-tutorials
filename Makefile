default: all
include Makefile.inc
VENDOR := vendor

all: ${VENDOR}/CuTest.o ${VENDOR}/remark.min.js

${VENDOR}/remark.min.js:
	curl -o $@ http://gnab.github.io/remark/downloads/remark-0.5.3.min.js
