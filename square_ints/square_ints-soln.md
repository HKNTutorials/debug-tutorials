# **Solution:** square_ints
## fillArray
```C
int* getArray() {
  // This function clearly should return an array, not NULL.
  return global_array;
}
```

```C
void fillArray(int *array, int startNum, int len) {
  ...
  /*
   * This statement was indexing with what it should have stored. When startNum
   * was large, this caused a segmentation fault. If you tried making startNum
   * small (but positive) you could have run this to completion, but found that
   * the first few numbers were uninitialized. A negative startNum would still
   * segfault.
   */
  array[i] = startNum + i;
  ...
}
```

---

# **Solution:** square_ints
## squareArray

```C
void squareArray(int *array, int len) {
  ...
  /*
   * Any test case would have failed. Reading the code was probably the fastest
   * way to find this one.
   */
  array[i] = array[i]*array[i];
  ...
}
```
