default: all
include Makefile.inc
VENDOR := vendor

all: ${VENDOR}/CuTest.o ${VENDOR}/remark.min.js

${VENDOR}/remark.min.js:
	curl -o $@ https://github.com/gnab/remark/releases/download/v0.5.3/remark-0.5.3.min.js
