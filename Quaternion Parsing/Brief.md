<h1>Quaternion Parsing</h1>
A quaternion contains 4 components; 1 Real Component and 3 Imaginary Components. The imaginary components are represented by the suffix `i, j, k`.

For example, `1 -2i + 3j - 4k` is a quaternion with `1` being the real component and `-2`, `3`, and `-4` being the imaginary components.

In this coding challenge you have to parse a string of a quaternion (ex. `"1 + 2i - 3j - 4k"`) into a list/array of coefficients (ex. `[1 2 -3 -4]`, with the real component first, then i, j, k). However, the quaternion string can be formatted in many different ways...

```
standard form: 1+2i-3j-4k
missing terms: 1-3k, 2i-4k
missing coefficients: i+j-k
It may not be in the right order: 2i-1+3k-4j
The coefficients may be integers or decimals: 7-2.4i+3.75j-4.0k
```

If you have missing terms, output 0 for those terms.

If you have missing coefficients, assume that the missing coefficient is 1.

There are some other things to note while parsing:

* There will always be a + or - between terms.
* You will always be passed valid input with at least 1 term, and without repeated components
* All numbers can be assumed to be valid
* You can change numbers into another form after parsing (ex. 3.0 => 3, 0.4 => .4, 7 => 7.0)

