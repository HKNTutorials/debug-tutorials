#!/usr/bin/env bash

# Auto generate single AllTests file for CuTest.
# Prints to stdout.
# Author: Asim Jalis
# Date: 2003-08-01
# Modified by: Tej Chajed
# Date: 2013-07-28

FILES=$*

echo '
/* This is auto-generated code. Edit at your own peril. */
#include <stdio.h>
#include <stdlib.h>

#include "CuTest.h"
'

# declare test functions as externs
cat $FILES | grep '^void Test' | 
    sed -e 's/(.*$//' \
        -e 's/$/(CuTest*);/' \
        -e 's/^/extern /'

echo \
'
void RunAllTests(void) 
{
    CuString *output = CuStringNew();
    CuSuite* suite = CuSuiteNew();
'

# Find and add tests
cat $FILES | grep '^void Test' | 
    sed -e 's/^void //' \
        -e 's/(.*$//' \
        -e 's/^/    SUITE_ADD_TEST(suite, /' \
        -e 's/$/);/'

echo \
'    
	CuSuiteRun(suite);
    CuSuiteSummary(suite, output);
    CuSuiteDetails(suite, output);
    printf("%s\n", output->buffer);
    CuStringDelete(output);
    CuSuiteDelete(suite);
}

int main(void) {
    RunAllTests();
}
'
