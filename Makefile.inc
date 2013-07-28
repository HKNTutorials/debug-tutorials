CC := clang
VENDOR := ../vendor
CFLAGS := -I${VENDOR} -g -std=c99 -Wall -Werror
TEST_BINARY = ${PROBLEM}_tests

all: ${TEST_BINARY}

test: ${TEST_BINARY}
	./${TEST_BINARY}

${PROBLEM}_tests.c: ${PROBLEM}.c
	${VENDOR}/make-tests.sh $< > $@

${TEST_BINARY}: ${PROBLEM}_tests.c ${PROBLEM}.o ${VENDOR}/CuTest.o
	${CC} ${CFLAGS} $^ -o $@

clean:
	rm -f *.o
	rm -f ${PROBLEM}_tests.c
	rm -f ${TEST_BINARY}
