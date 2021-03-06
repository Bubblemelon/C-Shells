# [My C/C++ Notes](#my-cc-notes)

Contents:

- [C Data Types](#c-data-types)

- [C Fundamentals](#c-fundamentals)

- [Functions](#functions)

- [Header Files](#header-files)

- [Interface](#interface)

- [Macros](#macros)

- [Parameters](#parameters)

- [Pointers](#pointers)

- [Preprocessor](#preprocessor)

- [Scope of Identifiers](#scope-of-identifiers)

- [Variables](#variables)

-----

### [Header Files](#header-files)

Contains mostly of, [Function Prototypes](#function-prototype).

> May contain, named CONSTANTS e.g. `INT_MAX` and `INT_MIN` , stream variables
> e.g. `cin` and `cout`, typedefs, etc.
>
> **Every identifier** must be declared before using.
>
> e.g. By doing `#include <math.h>`:
>
> (1) This tells the complier a number of math-oriented library function
> identifiers such as, `sqrt` since it contains the function prototype of
> `sqrt`.
>
> (2) The complier can verify if the function call/invocation is correct with
> respect to the number of parameters/arguments and their respective data types.

Most importantly, this **saves the trouble and clutter of specifying all the
library function prototypes at the beginning of the program** i.e. on the top of
the program before the _main_ function but after the preprocessor/directives.

By doing: `#include <headerfilename.h>`
> This tells the preprocessor to find the header file and insert the prototypes
> in to the program.

🍱 **Note**: This is part of the [Interface](#interface) section.

-----

### [Functions](#functions):

The definition of the _main_ function **usually appears first in a program**,
followed by the definitions of all other functions. <br/>

🎈 **main Function**: Program entry and Controls the program. Returns either 1
or 0. Usually zero for a successful execution. Program will still terminate without `return 0`; the compiler may produce a warning.

🎈 **Function calls**: is a call to a function that results in the execution of
the called function.
> e.g. `FunctionName(ActualParameterList);`

🎈 **Function Definition**: a function declaration that includes the body of the
function.
> Consists of two parts: **Function Heading** and **Function Body**.
>
> Function Heading: Its Formal Parameter List **must have the names of the
> variables/arguments specified**.
>
> Function body: Where the code for the procedure goes.

#### [Function Prototype](#function-prototype):

a function declaration that omits the body of the function (function body).
> Also known as a _forward declaration_：
>
> **Function prototypes are usually placed at the top of the program** after
> preprocessor definitions/#include directives and before the _main_ function.
>
> e.g. `ReturnType/void FunctionName(FormalParameterList);`
>
> The Formal Parameter List **must have the data types specified**, but **their
> variable names are optional**.

<br/>

There are two kinds of kind of subprograms, [voidfunctions](#void-functions) and **value-returning functions**.

#### [Void Functions](#void-functions)

This function does not return a function value to its caller, so it does not
finish with a return keyword.


🎈 **Naming Conventions**:

Should sound like an **action**. Name it as a verb or including a verb in in the
naming.


`return;`
> Only valid for void functions.
>
> Can be used anywhere in the body of the function, to control the immediate
> exit of the void function and return to the caller.

-----

### [Interface](#interface)

The specification of what a function does (not as code but as comments) and how
it is invoked (as function prototypes). This provides the **encapsulation** or
the hiding of how an implementation is made.
> `sqrt` from `math.h` can be effectively used without knowing how the `sqrt`
> function is written/implemented.
>
> It's implementation is hidden from view.

This further explains encapsulation:
> e.g. The algorithm of the functions can be modified and **the main function
> can remain the same (changes to the main function to compensate for the
> changes in the functions are unnecessary)**, as long as the interface remains
> the same.
>
> **Encapsulation** is the basis for team programming:
>
> An interface can be given to someone else, that person can develop the
> implementation for the functions specified (must conform with interface
> specification), knowing how it is implemented is unnecessary.

**Interface Design**:

1. Define the behaviour of the function i.e. what it does. [not how the function
   does it]
2. Mechanisms/methods to communicating with the function.

-----

### [Macros](#macros)

A macro defintion is preprocessing directive. It is a way to define constants.

```c
#define MONTHS_PER_YEAR 12

#define RECIPROCAL_OF_PI (1.0f / 3.14159f)
```

When a program is compiled the preprocessor replaces the macro with its associated value/expression.

Use all uppercase letters for macro definitions (a usage convention -- not a language requirement) and expressions should be in parentheses.

### [Parameters](#parameters)

🎈 **Actual Parameter**: Appears in a function call/invocation.

Its corresponding formal parameter may be either a _value or a reference
parameter_. Look at **function calls** for an example.

🎈 **Formal Parameters**:

There are two kinds of formal parameters.

1. **Value Parameters**:
> The default kind of parameter.
>
> The function receives **a copy** of value stored in the _actual parameter_'s
> value, from a function call.
>
> Appears in a function heading.

Since a value parameter is not receiving the location of an actual parameter,
the **actual parameter cannot be directly accessed or changed**.

The contents of any **value parameters and local variables are destroyed when a
function returns**. So Value Parameters **cannot be used to return information**
to calling code.

1. **Reference Parameters**:
> Declared with an `&` ampersand at the end of the data type name.
>
> The function receives **the location (memory address)** of the _actual
> parameter_ from a function call.
>
> Appears in a function heading.

A reference parameter is **allowed to inspect and modify** the caller's actual
parameter.
> The value left by the called function in the given location, is the value that
> the caller (the program that invoked the function) will find.

There is **only one copy** of the actual parameter, used by caller and called
function.

Generates a compile-time error when, a reference parameter receives anything
other than a variable name.

**The actual parameter must match the data type, the sequence and number of the
formal parameters**:

| Function Declarations:    | Return Type (e.g a Data Type) |Function Declaration | Parameter/Argument 1 | Parameter/Argument 2 |
| ------------------| ------------------| ---------------------| --------------------- | --------------------- |
| A Function Heading| `void`            | `FunctionName`    | `( int& somenumber,`  | `char someletter )`    |
|                   |                   |                      | a Formal Reference Parameter   | a Formal Value Parameter|
| A Function Call   | _Does not need to specify_ | `FunctionName`         | `( int_type_variable,` | `char_type_variable )` |
|                   |                   |                      |  an Actual Parameter | an Actual Parameter  |

🍱 **Note**:

If the data type of an actual parameter does not match with the **formal Value
parameter**, then **implicit type coercion** takes place.
> e.g. an actual parameter of a float type is coerced to an int type before it
> is passed to a function such as `FunctionName`.
>
> Void an **implicit type coercion**, by doing an explicit type cast/conversion
> and by not mixing data types.
>
> An **explicit type cast** looks like this, `someInt = int( someFloat + 0.5 )`.
>
> if `someFloat = 4.2` then `someInt = 5` because `4.2 + 0.5 = 4.7`, this float
> to int type cast rounds `4.7` to `5`.

If the data type of an actual parameter does not match with the **formal
Reference parameter**, then the following takes place:
1. C++ copies the value of the actual parameter into a temporary variable of the
   correct type.
2. Passes the address of the temporary variable to the reference parameter.
3. The temporary variable is destroyed when the function returns.

> **Result**: _No changes were made to the actual parameter_.
>
> Make sure that the data types of actual parameters match exactly with the
> formal parameters.

🎈 **Efficiency** of **Passing-by-Value** and **Passing-by-Reference**:

Passing-by-value may occupy many memory locations, whereas passing-by-reference
usually occupies a single location.

e.g. Simple data types such as, int, char and float have about the same
efficiency for both.


🎈 **Parameter Data Flow**

The flow of a variable/value/parameter (information) from the calling code to a
function and from the function back to the calling code.

| Data Flow of a Parameter | Parameter Passing Mechanism/Method |
| -------------------------| ---------------------------------- |
| Incoming/Input Parameter | **Pass-by-Value**: <br/> passes into the function; <br/><br/>Only inspects and uses the current value of parameter but does not modify it. |
| Outgoing/Output Parameter| **Pass-by-Reference**: <br/> goes out of the function; <br/><br/>Produces a new value for parameter without using the old value in anyway, i.e. simply replaces the old value without manipulating it. |
| Output & Input Parameter | **Pass-by-Reference**: <br/> two way direction; <br/><br/>Uses the old value and also produces a new value for the parameter.

-----
### [Pointers](#pointers)

Every variable has a memory address. Pointers are holders of a memory address
i.e. it is possible to store the address of a variable in a pointer-variable.

**Declaring a ➡️ Pointer**:  

`int *pInt;` is the same as `int * pInt;`

With the `*` asterisk next to the variable name, this gives the variable the
capability to hold a memory address of a variable with the type int.

**Initializing a Pointer**:

`pInt = 0;`

This above is a null pointer. Whereas `int *pInt;` _before it's been
initialized_ is considered as a **Wild Pointer**.

[In C++, while the `NULL` macro was inherited from C, the integer literal for
zero has been traditionally preferred to represent a null pointer constant.
However, C++11 has introduced an explicit `nullptr` constant to be used
instead.](https://en.wikipedia.org/wiki/Null_pointer)

**Storing the Address of a Variable in a Pointer**:

```
int someInt = 7;

pInt = &someInt; //second line
```

- Variables `someInt` and `pInt` must the same type.
- The "**Address-Of**" operator `&` indicates/refers to the address of a
  variable.
- If the second line, had this `pInt = someInt;` instead i.e. **without** `&`,
  then the pointer variable `pInt` would be assigned to the value of `someInt`.
  ( It is analogous to `pInt = 7;` )

**Indirection**:

Accessing the value at the address held by a pointer. Pointers **provide an
indirect way to get a value** held at its address.

`*` Dereferences: obtain the address of a data item held in another location
from (a pointer)

`&` Addresses:  a binary number which identifies a particular location in a data
storage system or computer memory; a numerical value which acts as a storage
address for the data

**The Difference between a Pointer and a Variable**:

Consider the following:
```
int myvar = 25;
int bar = 0;
int *foo = 0;
```
And then after this:
```
int *foo = &myvar;
int bar = myvar;
```

![Difference between a Pointer and a Variable Image](notes_img1.png)

[Link to
example](https://stackoverflow.com/questions/4955198/what-does-dereferencing-a-pointer-mean)

🍱 **Note**:

My notes on `Pointers` above is far from comprehensive. My understanding and
source of reference (aside from the Internet) comes from the book [Understanding
and Using C
Pointers](https://www.amazon.com/Understanding-Using-Pointers-Techniques-Management/dp/1449344186).

-----

### [Preprocessor](#preprocessor)

A program that acts as a filter during the compilation phase. Obeys commands that begin with `#`.

E.g. the `#include` or `#define` directive is handled by the preprocessor.  Also known as a
_preprocessor directive_.

The preprocessor expands an `#include` directive by **physically inserting**
contents of the header file i.e. `.h` files into the source program.

`< >` angle brackets tell the preprocessor to look for files in the **Standard
Include Directory** \- a location path in the computer system that contains all
the Standard header files.

The GNU GCC [Guide](https://gcc.gnu.org/onlinedocs/cpp/index.html#SEC_Contents)
to the C Preprocessor.

**A simplified overview of how C/C++ programs are converted to an executable object**:

```
Preprocessing ➞ Compiling ➞ Assembly ➞ Linking
```

* Compiling:
  > **Compiler** takes modified code from **preprocessor** or "preprocessed code" and translates it to assembly instructions that are  specific to the target processor architecture. The preprocessor is usually integrated with the compiler.

* Assembly:
  > into machine instructions (object code) and symbol tables.

* Linking:
  > The **linker** combines object code from assembler with additional code such as library functions e.g. `printf()`. Symbols in the object code get resolved to memory locations. All of this is to yield a complete executable program.

Files that can be generated:

`.i` is preprocessor's modification on the program. Use the `-E` flag/option when compiling to generate this file.

`.s` is assembly instructions from the compiler. Use the `-S` flag/option when compiling to generate this file.

`.out` is the default extention of the executable when a name is not specified.

`.o` files are objects. They are the output of the assembler and input to the linker/librarian. Use the `-c` flag/option to generate the object file. This is the instructions for the processor. Use,
```bash
hexdump filename.o
od filename.o
```
to see content in hex.

`.a` files are archives. They are groups of objects or static libraries and are also input into the linker.

To produce all intermidiate files from `gcc`, for example run:

```bash
gcc –Wall –save-temps filename.c –o filename
```
-----

### [Scope of Identifiers](#scope-of-identifiers)

The region of a program where it has legal reference to an identifier. Scope is
a **compile-time** issue.

The code below covers the following scopes:

1. local - identifiers declared within a block, extends the entire block from
   point of declaration.

2. global - identifiers declared anywhere outside of functions and classes,
   extends to the end of the entire program code file from point of declaration.


```
#include <iostream.h> // looks for a file in the Standard Library

void Function1( int , char& ) // function prototype

int a; // a global variable

int main()
{
  ...
}

// function definition
void Function1( int a, char& b2 ) // function heading: parameter variables a and b2 has the same scope as c and d
{

  // local variables to Function1
  int c = 1;
  int d;

  a * c; // parameter variable a (can be considered as a local variable)
         // has higher precedence over global variable a and prevents access to global a
         // name a to something else if using global a is needed
}

```
Scopes not covered in the code above:

3. class - identifiers declared within the class block, extends the entire block
   and [exceptions covered in this
   link](https://www.ibm.com/support/knowledgecenter/SS2LWA_12.1.0/com.ibm.xlcpp121.bg.doc/language_ref/cplr033.html).

4. non-local - identifiers declared outside a given block, i.e. if a block
   access any identifiers outside its own block has non-local access.

-----

### [Variables](#variables)

**Variable Definitions**:

Reserves a memory location for a variable. There can be only one variable
definition.
> e.g. `int someInt;`
>
> Both a declaration and a definition.

**Variable Declaration**:

Most variable declarations are usually specifically known as Variable
Definitions. Variable declarations can happen more than once.
> e.g. `extern int someInt;`
>
> This declaration states that `someInt` is a global variable from another file,
> and that no additional storage should be reserved for it.
>
> `someInt`\'s variable definition is located in that other file
>
> `extern` is a keyword allows references of global variables from another file.

**Initialization in a Declaration**:

```
int someInt; // variable declaration
someInt = 7; // assign initial value to variable

int someInt = 7; // initialization in a declaration
```

**Initializer**: The expression that specifies the initial value of a variable.

The right side of an assignment is conventionally called an **expression** and does not always have to be a numeric value.

Using an uninitialized variable may yield an unpredictable result.

**Variable Lifetimes**:

The amount/period of time during a program execution that an identifier/variable
has memory allocated to it. A **run-time** issue.

Storage Classes/Types:

1. **Automatic Variables**

  - Storage is allocated at block entry
  - Deallocated at block exit
  - Initialized to the specified value _each time_ control enters the block


2. **Static Variables**

  - Storage allocation remains for the duration of the entire program runtime
  - Deallocated when program terminates
  - All Global variables are static variables
  - Initialization _occurs only once_, the first time when the control reaches
    the declaration
  - Must have constant values as operands, the following is illegal:
    ```
    void FunctionName( int param )
    {
      static int someInt = param + 1; // this is illegal

      static int otherInt = 1 * 2; // not illegal
    }
    ```


🍱 **Note**:

Local variables (declared within a block) are **automatic*** variables by
default.

Using `static` on a local variable, will allow its storage lifetime to persist
from function call to call (this `static` local variable's value is retained
from call to call).

Remember identifier are case-sensitive, avoid obfuscation e.g. naming having the variable names, `var` and `vAr` in a program isn't meaningful and can cause confusion.

There is no limit on the maximum length of an identifier. C99 Standard requires only the first 63 characters while C89 requires the first 31.

Keywords can't be used as identifiers, and most are e.g. in the standard libary lowercase letters. Avoid using identifiers that begin with an `_` underscore, since it might coincide with a keyword or an already defined function from an included library.

Use camelcase or hypens between words in identifiers.

Groups of characters that can't be split up without changing their meaning are called **tokens**, e.g. operators, string literals, function and variable names.

### [C Data Types](#c-data-types)

The following table was adapted from [Wikipedia](https://en.wikipedia.org/wiki/C_data_types).

<table>
<thead>
<tr class="header">
<th><p>Type</p></th>
<th><p>Explanation</p></th>
<th><p>Minimum size (bits)</p></th>
<th><p>Format specifier</p></th>
</tr>
</thead>
<tbody>
<tr class="odd">
<td><p><code>char</code></p></td>
<td><p>The smallest addressable unit in a machine that would contain the basic character set. It can be treated as an <code>unsigned int</code>, and uses  <code>CHAR_BIT</code> bits.</p></td>
<td><p>8</p></td>
<td><p><code>%c</code></p></td>
</tr>
<tr class="even">
<td><p><code>signed char</code></p></td>
<td><p>Represents the minimum [−127 , +127] range.</p></td>
<td><p>8</p></td>
<td><p><code>%c</code> <small>( use <code>%hhi</code> for numerical output )</small></p></td>
</tr>
<tr class="odd">
<td><p><code>unsigned char</code></p></td>
<td><p>Represents the minimum [0, 255] range.</p></td>
<td><p>8</p></td>
<td><p><code>%c</code> <small>( use <code>%hhu</code> for numerical output )</small></p></td>
</tr>
<tr class="even">
<td><p><code>short</code><br /><br />
<code>short int</code><br /><br />
<code>signed short</code><br /><br />
<code>signed short int</code></p></td>
<td><p>Represents the minimum [−32,767 , +32,767] range.]</p></td>
<td><p>16</p></td>
<td><p><code>%hi</code> <br/> <code>%hd</code></p></td>
</tr>
<tr class="odd">
<td><p><code>unsigned short</code><br /><br />
<code>unsigned short int</code></p></td>
<td><p>Represents the minimum the [0, 65,535] range.</p></td>
<td><p>16</p></td>
<td><p><code>%hu</code></p></td>
</tr>
<tr class="even">
<td><p><code>int</code><br /><br />
<code>signed</code><br /><br />
<code>signed int</code></p></td><br />
<td><p>Represents the minimumthe [−32,767 , +32,767] range.</p></td>
<td><p>16</p></td>
<td><p><code>%i</code> <br/> <code>%d</code></p></td>
</tr>
<tr class="odd">
<td><p><code>unsigned</code><br /><br />
<code>unsigned int</code></p></td>
<td><p>Represents the minimum [0, 65,535] range.</p></td>
<td><p>16</p></td>
<td><p><code>%u</code></p></td>
</tr>
<tr class="even">
<td><p><code>long</code><br /><br />
<code>long int</code><br /><br />
<code>signed long</code><br /><br />
<code>signed long int</code></p></td>
<td><p>Represents the minimum <br/> [−2,147,483,647 , +2,147,483,647] range.</p></td>
<td><p>32</p></td>
<td><p><code>%li</code> <br/> <code>%ld</code></p></td>
</tr>
<tr class="odd">
<td><p><code>unsigned long</code><br /><br />
<code>unsigned long int</code></p></td>
<td><p>Represents the minimum [0, 4,294,967,295] range.</p></td>
<td><p>32</p></td>
<td><p><code>%lu</code></p></td>
</tr>
<tr class="even">
<td><p><code>long long</code><br /><br />
<code>long long int</code><br /><br />
<code>signed long long</code><br /><br />
<code>signed long long int</code></p></td>
<td><p>Represents the minimum <br> [−9,223,372,036,854,775,807 , +9,223,372,036,854,775,807] range. Introduced in the C99 Standard.</p></td>
<td><p>64</p></td>
<td><p><code>%lli</code> </br> <code>%lld</code></p></td>
</tr>
<tr class="odd">
<td><p><code>unsigned long long</code><br /><br />
<code>unsigned long long int</code></p></td>
<td><p>Represents the minimum [0, +18,446,744,073,709,551,615] range.  Introduced in the C99 Standard.</p></td>
<td><p>64</p></td>
<td><p><code>%llu</code></p></td>
</tr>
<tr class="even">
<td><p><code>float</code></p></td>
<td><p>To store numeric values after the decimal point; decimal point "floats". This type has a <i>single-precision floating-point</i>. Used when the amount of precision isn't critical.<br/>Modern computers follow the IEEE Standard 754, also known as IEC 60559. Represents the minimum </br> [1.17549 x 10^(-38), 3.40282 x 10^(38)] range. 6 digit precision.</p></td>
<td><p>32</p></td>
<td><p><code>%f</code> <code>%F</code><br />
<code>%g</code> <code>%G</code><br />
<code>%e</code> <code>%E</code><br />
<code>%a</code> <code>%A</code></p></td>
</tr>
<tr class="odd">
<td><p><code>double</code></p></td>
<td><p>This type has a <i>double-precision floating-point</i>. Greater precision -- enough for most programs.<br/>Modern computers follow the IEEE Standard 754, also known as IEC 60559. Represents the minimum </br> [2.22507 x 10^(-308), 1.79769 x 10^(308)]. 15 digit precision.</p></td>
<td><p>64</p></td>
<td><p><code>%lf</code> <code>%LF</code><br />
<code>%lg</code> <code>%LG</code><br />
<code>%le</code> <code>%LE</code><br />
<code>%la</code> <code>%LA</code></p></td>
</tr>
<tr class="even">
<td><p><code>long double</code></p></td>
<td><p>This type has an <i>extended-precision floating point</i>. Ultimate precision -- rarely used.<br/>Modern computers follow the IEEE Standard 754, also known as IEC 60559. <a href="https://en.wikipedia.org/wiki/Quadruple-precision_floating-point_format#IEEE_754_quadruple-precision_binary_floating-point_format:_binary128">Extremely large range</a>. Around 33 digit precision.</p></td>
<td><p>128</p></td>
<td><p><code>%Lf</code> <code>%LF</code><br />
<code>%Lg</code> <code>%LG</code><br />
<code>%Le</code> <code>%LE</code><br />
<code>%La</code> <code>%LA</code></p></td>
</tr>
</tbody>
</table>

Use the `<limits.h>` library for a [list of mins and maxs for each data-type](https://docs.microsoft.com/en-us/cpp/c-language/cpp-integer-limits?view=vs-2019).

The table above was initially in `.wiki` or MediaWiki format and was converted to `gfm` or GitHub Flavored Markdown using [Pandoc](
https://pandoc.org/demos.html). The following the command was used:


```bash
pandoc -w gfm filename.wiki -o filename.md
```

### [C Fundamentals](#c-fundamentals)

A [list of programs in C](../Misc/c-fundamentals/README.md) ordered from ascending complexity, where concepts build from each other.

[Go back to the TOP 🔝 of this page.](#my-cc-notes)