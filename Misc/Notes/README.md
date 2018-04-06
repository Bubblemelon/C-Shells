## My C/C++ Notes:

contents:

- [Functions](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#functions)  

- [Header Files](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#header-files)  

- [Parameters](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#parameters)

- [Preprocessor](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#preprocessor)    

-----

### [Header Files](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#header-files)  

Contains mostly of, [Function Prototypes](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#function-proto).  

> May contain, named CONSTANTS e.g. `INT_MAX` and `INT_MIN` , stream variables e.g. `cin` and `cout`, typedefs, etc.  
>
> **Every identifier** must be declared before using.
>
> e.g. By doing `#include <math.h>`:  
>
> (1) This tells the complier a number of math-oriented library function identifiers such as, `sqrt` since it contains the function prototype of `sqrt`.
>
> (2) The complier can verify if the function call/invocation is correct with respect to the number of parameters/arguments and their respective data types.  

Most importantly, this **saves the trouble and clutter of specifying all the library function prototypes at the beginning of the program** i.e. on the top of the program before the _main_ function but after the preprocessor/directives.

By doing:
`#include <headerfilename.h>`  
> This tells the preprocessor to find the header file and insert the prototypes in to the program.   

-----

### [Functions](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#functions):  

The definition of the _main_ function **usually appears first in a program**, followed by the definitions of all other functions.

🎈 **main Function**: Program entry and Controls the program. Returns either 1 or 0. Usually zero for a successful execution.   

There are two kinds of kind of subprograms, [void functions](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#void-funct) and **value-returning functions**.

🎈 **Function calls**: is a call to a function that results in the execution of the called function.
> e.g. `FunctionName(ActualParameterList);`  

🎈 **Function Definition**: a function declaration that includes the body of the function.  
> Consists of two parts:
> **Function Heading** and **Function Body**.  
>
> Function Heading:  
> Its Formal Parameter List **must have the names of the variables/arguments specified**.  
>
> Function body:   
> Where the code for the procedure goes.

#### [Function Prototype](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#function-proto):  

a function declaration that omits the body of the function (function body).
> Also known as a _forward declaration_：
>
> **Function prototypes are usually placed at the top of the program** after preprocessor definitions/#include directives and before the _main_ function.
>   
> e.g. `ReturnType/void FunctionName(FormalParameterList);`  
>
> The Formal Parameter List **must have the data types specified**, but **their variable names are optional**.

##### [Void Functions](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#void-funct)

This function does not return a function value to its caller, so it does not finish with a return keyword.   

🎈 **Naming Conventions**:  

Should sound like an **action**. Name it as a verb or including a verb in in the naming.


`return;`  
> Only valid for void functions.
>   
> Can be used anywhere in the body of the function, to control the immediate exit of the void function and return to the caller.  

-----

### [Parameters](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#parameters)

🎈 **Actual Parameter**:  
Appears in a function call/invocation.   

Its corresponding formal parameter may be either a _value or a reference parameter_. Look at **function calls** for an example.  

🎈 **Formal Parameters**:  

There are two kinds of formal parameters.

1. **Value Parameters**:
> The default kind of parameter.  
>
> The function receives **a copy** of value stored in the _actual parameter_'s value, from a function call.  
>
> Appears in a function heading.  

Since a value parameter is not receiving the location of an actual parameter, the **actual parameter cannot be directly accessed or changed**.

The contents of any **value parameters and local variables are destroyed when a function returns**. So Value Parameters **cannot be used to return information** to calling code.

2. **Reference Parameters**:  
> Declared with an `&` ampersand at the end of the data type name.
>
> The function receives **the location (memory address)** of the _actual parameter_ from a function call.   
>
> Appears in a function heading.

A reference parameter is **allowed to inspect and modify** the caller's actual parameter.
> The value left by the called function in the given location, is the value that the caller (the program that invoked the function) will find.   

There is **only one copy** of the actual parameter, used by caller and called function.  

Generates a compile-time error when, a reference parameter receives anything other than a variable name.

**The actual parameter must match the data type, the sequence and number of the formal parameters**:

| Function Declarations:    | Return Type (e.g a Data Type) |Function Declaration | Parameter/Argument 1 | Parameter/Argument 2 |               
| ------------------| ------------------| ---------------------| --------------------- | --------------------- |
| A Function Heading| `void`            | `FunctionName`    | `( int& somenumber,`  | `char someletter )`    |
|                   |                   |                      | a Formal Reference Parameter   | a Formal Value Parameter|
| A Function Call   | _Does not need to specify_ | `FunctionName`         | `( int_type_variable,` | `char_type_variable )` |
|                   |                   |                      |  an Actual Parameter | an Actual Parameter  |

🍱 **Note**:  

If the data type of an actual parameter does not match with the **formal Value parameter**, then **implicit type coercion** takes place.
> e.g. an actual parameter of a float type is coerced to an int type before it is passed to a function such as `FunctionName`.
>
> Void an **implicit type coercion**, by doing an explicit type cast/conversion and by not mixing data types.  
>
> An **explicit type cast** looks like this, `someInt = int( someFloat + 0.5 )`.
>
> if `someFloat = 4.2` then `someInt = 5` because `4.2 + 0.5 = 4.7`, this float to int type cast rounds `4.7` to `5`.

If the data type of an actual parameter does not match with the **formal Reference parameter**, then the following takes place:
1. C++ copies the value of the actual parameter into a temporary variable of the correct type.  
2. Passes the address of the temporary variable to the reference parameter.  
3. The temporary variable is destroyed when the function returns.

> **Result**: _No changes were made to the actual parameter_.  
>
> Make sure that the data types of actual parameters match exactly with the formal parameters.

🎈 **Efficiency** of **Passing-by-Value** and **Passing-by-Reference**:  

Passing-by-value may occupy many memory locations, whereas passing-by-reference usually occupies a single location.  

e.g. Simple data types such as, int, char and float have about the same efficiency for both.   


🎈 **Parameter Data Flow**

The flow of a variable/value/parameter (information) from the calling code to a function and from the function back to the calling code.  

| Data Flow of a Parameter | Parameter Passing Mechanism/Method |
| -------------------------| ---------------------------------- |
| Incoming/Input Parameter | **Pass-by-Value**: <br/> passes into the function; <br/><br/>Only inspects and uses the current value of parameter but does not modify it. |
| Outgoing/Output Parameter| **Pass-by-Reference**: <br/> goes out of the function; <br/><br/>Produces a new value for parameter without using the old value in anyway. |
| Output & Input Parameter | **Pass-by-Reference**: <br/> two way direction; <br/><br/>Uses the old value and also produces a new value for the parameter.

-----

### [Preprocessor](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#preprocessor)  

A program that acts as a filter during the compilation phase.  

The `#include` directive is handled by the preprocessor.  Also known as a _preprocessor directive_.   

The preprocessor expands an `#include` directive by physically inserting contents of the header file i.e. `.h` files into the source program.  

`< >` angle brackets tell the preprocessor to look for files in the **Standard Include Directory** \- a location path in the computer system that contains all the Standard header files.
