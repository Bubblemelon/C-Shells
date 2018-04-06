## My C/C++ Notes:

contents:

- [Functions](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#functions)  

- [Header Files](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#functions#header-files)  

### [Header Files](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#functions#header-files)  

Contains mostly of, [Function Prototypes](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#functions-proto).  

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


### [Functions](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#functions):  

The definition of the _main_ function **usually appears first in a program**, followed by the definitions of all other functions.

**main Function**: Program entry and Controls the program. Returns either 1 or 0. Usually zero for a successful execution.   

There are two kinds of kind of subprograms, **void functions** and **value-returning functions**.

**Function calls**: is a call to a function that results in the execution of the called function.
> e.g. `ReturnType/void FunctionName(ActualParameterList);`  

**Function Definition**: a function declaration that includes the body of the function.  
> Consists of two parts:
> **Function Heading** and **Function Body**.  
>
> Function Heading:  
> Its Formal Parameter List **must have the names of the variables/arguments specified**.

**[Function Prototype](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#functions-proto)**: a function declaration that omits the body of the function (function body).
> Also known as a _forward declaration_：
>
> **Function prototypes are usually placed at the top of the program** after preprocessor definitions/#include directives and before the _main_ function.
>   
> e.g. `ReturnType/void FunctionName(FormalParameterList);`  
>
> The Formal Parameter List **must have the data types specified**, but **their variable names are optional**.

##### Void Functions  

This function does not return a function value to its caller, so it does not finish with a return keyword.   

**Naming Conventions**:  

Should sound like an **action**. Name it as a verb or including a verb in in the naming.


`return;`  
> Only valid for void functions.  
> Can be used anywhere in the body of the function, to control the immediate exit of the void function and return to the caller.   
