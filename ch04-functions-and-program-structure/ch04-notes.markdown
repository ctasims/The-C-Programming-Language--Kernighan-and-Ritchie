# Chapter 4: Functions and Program Structure

## Summary

1. Break code into smaller portions to improve testability, refactoring, modularity.
2. Be aware of expected and given return value types.
3. Use external variables sparingly when data must be shared between functions.
4. `extern` declares a variable but does not define it.
5. Header files centralize the definitions and declarations shared amongst files in an application.
6. `static` external variables or funcs are only accessible inside their file. `static` internal variables persist through function calls.
7. Use `register` declaration with heavily used variables to store in register.
8. Variables can be defined inside blocks.
9. Variable types initialize differently. Explicit is better than implicit!
10. Recursion can make code more compact and intuitive.
11. The preprocessor handles definitions, includes, macros, etc. before compilation.


## 4.1 Basics of Functions
Use functions to separate functionality and decouple code. This leads to easier testing, readability and modularity.

Returned expressions are converted to the return type, if necessary.

Much of compilation and linking is machine-dependent.


## 4.2 Functions Returning Non-integers
We can declare functions before usage to explicitly state their return type and input parameter types. These must match the later definition!


## 4.3 External Variables
A variable defined outside any function is `external`. Functions are always external.
External variables are globally accessible. 
External variables provide an alternative to passing in arguments, but be careful about the dependence this creates, as well as any side effects. External variables can also make it harder to test functions.

Internal (automatic) variables are inside a function. They are created upon function call and cleaned up when the function returns.


## 4.4 Scope Rules
An external variable or function is in scope from its declaration until the end of its file. To use an external variable elsewhere, such as in a different file, the `extern` identifier is required.

Note that a declaration only announces the properties (e.g. type) of a variable. A declaration does not cause storage to be set aside, but a definition does.

One definition, but possibly many declarations.


## 4.5 Header Files
Header files provide a means of organizing variables and functions amongst many disparate files, so that they can be included in other files as necessary.

Header files are used with the `#include <header.h>` expression.


## 4.6 Static Variables
An external variable or a function with a `static` identifier is private to its file and cannot be accessed by other files. In other words, its scope is limited to the end of its current file.

`static` also causes internal variables to persist through function calls. This allows for "permanent" storage within a single function.


## 4.7 Register Variables
The `register` declaration causes a primitive variable to be kept in a register. This is useful for heavily-used variables. Note that the compiler may ignore this declaration based on its own optimization routines.

Only automatic variables and function parameters can be declared with `register`.


## 4.8 Block Structure
Variables can be defined in a block-structured fashion, causing their scope to be that block only. Note that a static variable is only initialized the first time a block is entered, whereas automatic variables are initialized every time.

Automatic variables can be used to hide external variables or functions, but this practice can lead to nasty errors and confusion.


## 4.9 Initialization
External and static variables are initialized to 0, while automatic and register variables are initialized to garbage values.

External and static variables can only be initialized with a constant expression. Initialization is only performed once, upon the first execution of their block/function.

Arrays can be initialized with a given number of empty slots, or with actual values.


## 4.10 Recursion
Recursive functions can call themselves. This causes another function block to be pushed onto the stack. Recursive functions "unwind" when executing, so the last one called finishes first. Every invocation gets its own set of automatic variables.

Recursive functions may not be faster or smaller but they can be more intuitive and compact.


## 4.11 The C Preprocessor
The preprocessor performs various processing duties before compilation occurs. It:

* replaces `#include` expressions with the file contents.
* puts `#define` calls wherever the name occurs in the file.
* Handles macros, provide compact utility by expanding into in-line code.

Be careful with macros as they come with a few pitfalls.
Since they are expanded into code, they can cause unexpected side effects.

`#expr` in a macro to put the actual parameter value.

`##` to concatenate arguments.

The preprocessor also handles conditional inclusion using `#if`, `#elif`, `#endif`, etc.
Use this to, e.g. check if a header file is already defined.

