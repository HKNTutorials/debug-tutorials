# **Solution:** floating_point
```C
float sumRange(float start, float end, float increment) { ...
  // the loop should continue only while f is less than end
  for (float f = start; f < end; f += increment) { ...
```

- Don't use == to compare floats. Always use comparisons.

???

If two floats should be the same, test that they are within a certain distance
of each other (this is what the tests do: they check that the expected and
actual values are within a certain tolerance of each other). This is
particularly important because some values can't be exactly represented in
floating point so that even a precise result is off by a small error (on the
order of 2^(-23) or 2^(-52) for single and double precision, respectively) that
can't be helped.
