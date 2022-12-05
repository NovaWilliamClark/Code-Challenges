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

<h2> TESTS </h2>

`"1 + 2i + 3j + 4k"` => `{1, 2, 3, 4}`

`"-1 + 3i -3j+7k"` => `{-1, 3, -3, 7}`

`"-1-4i-9j-2k"` => `{-1, -4, -9, -2}`

`"17-16i-15j-14k"` => `{17, -16, -15, -14}`

`"7+2i"` => `{7, 2, 0, 0}`

`"2i-6k"` => `{0, 2, 0, -6}`

`"1-5j+2k"` =>`{1, 0, -5, 2}`

`"3+4i-9k"` => `{3, 4, 0, -9}`

`"42i+j-k"` => `{0, 42, 1, -1}`

`"6-2i+j-3k"` => `{6, -2, 1, -3}`

`"1+i+j+k"` => `{1, 1, 1, 1}`

`"-1-i-j-k"` => `{-1, -1, -1, -1}`

`"16k-20j+2i-7"` => `{-7, 2, -20, 16}`

`"i+4k-3j+2"` => `{2, 1, -3, 4}`

`"5k-2i+9+3j"` => `{9, -2, 3, 5}`

`"5k-2j+3"` => `{3, 0, -2, 5}`

`"1.75-1.75i-1.75j-1.75k"` => `{1.75, -1.75, -1.75, -1.75}`

`"2.0j-3k+0.47i-13"` => `{-13, 0.47, 2.0, -3}`

`"5.6-3i"` => `{5.6, -3, 0, 0}`

`"k-7.6i"` => `{0, -7.6, 0, 1}`

`"0"` => `{0, 0, 0, 0}`

`"0j+0k"` => `{0, 0, 0, 0}`

`"-0j"` => `{0, 0, 0, 0}`

`"1-0k"` => `{1, 0, 0, 0}`
