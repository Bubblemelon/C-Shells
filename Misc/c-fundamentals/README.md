# [C Fundamentals](#c-fundamentals)

A list of programs in C, ordered from simple to complex.

- [C Fundamentals](#c-fundamentals)
  - [arrays.c](#arraysc)
  - [loan.c](#loanc)
  - [fahrenheit-to-celsius.c](#fahrenheit-to-celsiusc)

## [arrays.c](#arraysc)

Basic array usage, with four functions that returns:

1. The sum of the 1st and 3rd element.
2. The sum of all elements a given subarray.
3. The largest subarray sum.
4. The largest sum from the elements in an array, e.g. ignores negative elements.

Uses `sizeof()` array over `sizeof()` a single element to find the number of elements in the array.

More notes on implementation in [arrays.c](Misc/c-fundamentals/arrays.c).

## [loan.c](#loanc)

A program that calculates the remaining balance of a loan after the 1st to the 5th monthly payments.

Notes on `float`:
- Often used as an approximation of a number.
- Append "f" for float constants e.g. `const float var = 12.3f;`
- Use `%.nf` to specify `n` digits after the decimal point, e.g. `%.3f` is three digits after the decimal point.

More notes on implementation in [loan.c](Misc/c-fundamentals/loan.c).
