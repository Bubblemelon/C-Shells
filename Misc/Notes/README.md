## My C/C++ Notes:

contents:

- [Functions](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#functions)  

- [Header Files](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#header-files)

- [Interface](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#interface)

- [Parameters](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#parameters)

- [Preprocessor](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#preprocessor)

- [Scope of Identifiers](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#scope)

- [Variables](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#variables)

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

🍱 **Note**:  
This is part of the [Interface](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#interface) section.

-----

### [Functions](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#functions):  

The definition of the _main_ function **usually appears first in a program**, followed by the definitions of all other functions.
<br/>

🎈 **main Function**: Program entry and Controls the program. Returns either 1 or 0. Usually zero for a successful execution.   

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

<br/>

There are two kinds of kind of subprograms, [void functions](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#void-funct) and **value-returning functions**.  

#### [Void Functions](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#void-funct)   

This function does not return a function value to its caller, so it does not finish with a return keyword.    


🎈 **Naming Conventions**:  

Should sound like an **action**. Name it as a verb or including a verb in in the naming.


`return;`  
> Only valid for void functions.
>   
> Can be used anywhere in the body of the function, to control the immediate exit of the void function and return to the caller.  

-----

### [Interface](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#interface)    

The specification of what a function does (not as code but as comments) and how it is invoked (as function prototypes). This provides the **encapsulation** or the hiding of how an implementation is made.  
> `sqrt` from `math.h` can be effectively used without knowing how the `sqrt` function is written/implemented.  
>
> It's implementation is hidden from view.  

This further explains encapsulation:  
> e.g. The algorithm of the functions can be modified and **the main function can remain the same (changes to the main function to compensate for the changes in the functions are unnecessary)**, as long as the interface remains the same.    
>
> **Encapsulation** is the basis for team programming:  
>
> An interface can be given to someone else,  
> that person can develop the implementation for the functions specified (must conform with interface specification),  
> knowing how it is implemented is unnecessary.  

**Interface Design**:  

1. Define the behaviour of the function i.e. what it does. [not how the function does it]
2. Mechanisms/methods to communicating with the function.

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
| Outgoing/Output Parameter| **Pass-by-Reference**: <br/> goes out of the function; <br/><br/>Produces a new value for parameter without using the old value in anyway, i.e. simply replaces the old value without manipulating it. |
| Output & Input Parameter | **Pass-by-Reference**: <br/> two way direction; <br/><br/>Uses the old value and also produces a new value for the parameter.

-----

### [Preprocessor](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#preprocessor)  

A program that acts as a filter during the compilation phase.  

The `#include` directive is handled by the preprocessor.  Also known as a _preprocessor directive_.   

The preprocessor expands an `#include` directive by physically inserting contents of the header file i.e. `.h` files into the source program.  

`< >` angle brackets tell the preprocessor to look for files in the **Standard Include Directory** \- a location path in the computer system that contains all the Standard header files.  

-----

### [Scope of Identifiers](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#scope)  

The region of a program where it has legal reference to an identifier. Scope is a **compile-time** issue.

The code below covers the following scopes:  

1. local - identifiers declared within a block, extends the entire block from point of declaration.

2. global - identifiers declared anywhere outside of functions and classes, extends to the end of the entire program code file from point of declaration.  


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

3. class - identifiers declared within the class block, extends the entire block and [exceptions covered in this link](https://www.ibm.com/support/knowledgecenter/SS2LWA_12.1.0/com.ibm.xlcpp121.bg.doc/language_ref/cplr033.html).  

4. non-local - identifiers declared outside a given block, i.e. if a block access any identifiers outside its own block has non-local acces.  

-----

### [Variables](https://github.com/Bubblemelon/C-Shells/blob/master/Misc/Notes/README.md#variables)  

**Variable Definitions**:  

Reserves a memory location for a variable. There can be only one variable definition.
> e.g. `int someInt;`  
>
> Both a declaration and a definition.  

**Variable Declaration**:

Most variable declarations are usually specifically known as Variable Definitions. Variable declarations can happen more than once.
> e.g. `extern int someInt;`  
>  
> This declaration states that `someInt` is a global variable from another file, and that no additional storage should be reserved for it.
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


**Variable Lifetimes**:

The amount/period of time during a program execution that an identifier/variable has memory allocated to it. A **run-time** issue.

Storage Classes/Types:  

1. **Automatic Variables**   

  - Storage is allocated at block entry  
  - Deallocated at block exit  
  - Initialized to the specified value _each time_ control enters the block


2. **Static Variables**  

  - Storage allocation remains for the duration of the entire program runtime  
  - Deallocated when program terminates  
  - All Global variables are static variables  
  - Initialization _occurs only once_, the first time when the control reaches the declaration
  - Must have constant values as operands, the following is illegal:
    ```
    void FunctionName( int param )
    {
      static int someInt = param + 1; // this is illegal

      static int otherInt = 1 * 2; // not illegal
    }
    ```


🍱 **Note**:  

Local variables (declared within a block) are **automatic*** variables by default.

Using `static` on a local variable, will allow its storage lifetime to persist from function call to call (this `static` local variable's value is retained from call to call).
