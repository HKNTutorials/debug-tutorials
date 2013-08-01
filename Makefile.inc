# set PROBLEM to the name of your c source
# LEVEL should be the path to this directory (.., for example)
CC := clang
LIB = ${LEVEL}/lib
INCLUDE = ${LEVEL}/include
BIN = ${LEVEL}/bin
ASSETS = ${LEVEL}/assets
CFLAGS := -g -std=c99 -Wall -Werror -I${INCLUDE}
TEST_BINARY = ${PROBLEM}_tests

test: ${TEST_BINARY}
	${BIN}/timeout.py ./${TEST_BINARY}

${PROBLEM}_tests.c: ${PROBLEM}.c
	${BIN}/make-tests.sh $< > $@

${TEST_BINARY}: ${PROBLEM}_tests.c ${PROBLEM}.o ${LIB}/CuTest.o ${LIB}/testlib.o
	${CC} ${CFLAGS} $^ -o $@

clean:
	rm -f *.o
	rm -f ${PROBLEM}_tests.c
	rm -f ${TEST_BINARY}
