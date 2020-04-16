# [C Fundamentals](#c-fundamentals)

A list of programs in C, ordered from simple to complex.

- [C Fundamentals](#c-fundamentals)
  - [arrays.c](#arraysc)
  - [digit-sum.c](#digit-sumc)
  - [factorial.c](#factorialc)
  - [fahrenheit-to-celsius.c](#fahrenheit-to-celsiusc)
  - [gcd.c](#gcdc)
  - [half-tree-star.c](#half-tree-starc)
  - [integer-promotion.c](#integer-promotionc)
  - [loan.c](#loanc)
  - [max-values.c](#max-valuesc)

## [arrays.c](#arraysc)

Basic array usage, with four functions that returns:

1. The sum of the 1st and 3rd element.
2. The sum of all elements a given subarray.
3. The largest subarray sum.
4. The largest sum from the elements in an array, e.g. ignores negative elements.

Uses `sizeof()` array over `sizeof()` a single element to find the number of elements in the array.

More notes on implementation in [arrays.c](Misc/c-fundamentals/arrays.c).

## [digit-sum.c](#digit-sumc)

A program that returns the sum of digits from a user entered number. e.g. given the number `123`, the output would be `6`.

Uses the type `long int` for mutation and formatted printing using the placeholder `%ld`. The modulo operator was used to get Nth place of a digit, from the least significant digit or from right to left of the number, e.g. `3 + 2 + 1 = 6`

## [factorial.c](#factorialc)

A classic implementation of the factorial expression, this uses recursion and iteration where both achieves the same result of `n!`.

## [fahrenheit-to-celsius.c](#fahrenheit-to-celsiusc)

A program that converts fahrenheit to celsius, using the formula `(°F − 32) × 5/9 = 0°C`.

This program shows the difference between using `int`s and `float`s, the latter adds precision while the former truncates decimals and rounds down, e.g. `0.5` becomes `0`. This program defines the conversion factor as a macro.

## [gcd.c](#gcdc)

A classic implementation of finding the greatest common divisor (GCD) between two values as user input.

## [half-tree-star.c](#half-tree-starc)

This program prints half a Christmas tree using asterisks or the `*` star symbol. No specific C concepts in particular, this is to show the different ways to achieve the same result e.g. via recursion or with iteration.

See [half-tree-star.c](Misc/c-fundamentals/half-tree-stars.c) for example output.

## [integer-promotion.c](#integer-promotionc)

This program mimic functions from `\usr\includes\ctypes.h`. The purpose is to demonstrate type promotion, specifically integer promotion.

Type promotion can occur implicitly to avoid arithmetic overflows and to allow different types to exist in an expression. Arithmetic operations on `char` and `short` are always promoted to type signed `int` or larger.

For example, when doing arithmetic on `'z'` of type `char`, it will be promoted to an `int` and take the [ASCII](https://www.ibm.com/support/knowledgecenter/ssw_aix_72/network/conversion_table.html) decimal value `122`.

See this written discussion response on [integer promotion on StackOverFlow](https://stackoverflow.com/a/46073296/7072506), if only everyone took the time to write like that.

More notes on implementation in [integer-promotion.c](Misc/c-fundamentals/integer-promotion.c).

## [loan.c](#loanc)

A program that calculates the remaining balance of a loan after the 1st to the 5th monthly payments.

Notes on `float`:
- Often used as an approximation of a number.
- Append "f" for float constants e.g. `const float var = 12.3f;`
- Use `%.nf` to specify `n` digits after the decimal point, e.g. `%.3f` is three digits after the decimal point.

More notes on implementation in [loan.c](Misc/c-fundamentals/loan.c).

## [max-values.c](#max-valuesc)

A program that utilizes `limits.h`, and `time.h`. The purpose is to demonstrate a data type's numeric min and max range, and the amount of time it takes to iterate the entire range. The data types measured are `short int`, `unsigned int` and `unsigned long`.

See extensive notes on implementation in [max-values.c](Misc/c-fundamentals/max-values.c).