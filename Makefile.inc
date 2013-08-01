# set PROBLEM to the name of your c source
# LEVEL should be the path to this directory (.., for example)
CC := clang
LIB = ${LEVEL}/lib
INCLUDE = ${LEVEL}/include
BIN = ${LEVEL}/bin
ASSETS = ${LEVEL}/assets
CFLAGS := -g -std=c99 -Wall -Werror -I${INCLUDE}
TEST_BINARY = ${PROBLEM}_tests
