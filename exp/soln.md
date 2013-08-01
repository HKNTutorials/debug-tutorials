# **Solution:** exp
```C
  int factorial(int n) {
    ...
    /*
     * this was the culprit: result should be initialized to 1 since the loop
     * multiplies result by new values
     */
    int result = 1;
    ...
  }
```

???

- Note that the `exponential` function did not have any bugs
- This example highlights the value of tests: the factorial tests indicated
  there was a problem in this function, and the exponential tests gave
  confidence that this was the only bug
