# Chapter 1: A Tutorial Introduction #

## Getting started ##
Note that not all the important bits of this chapter are listed here.
Topics like logic operators are review for me, and are skipped.

The `main` function must be present and begins the execution of a program.  
`#include <>` tells the compiler to include a library.  


## 1.2 Variables and Arithmetic Expressions ##
All variables must be declared before use.  
int, float, char, short, long, double.  
`%d` to print integers, `%f` for floats.  


## 1.3 The For Statement ##

    int i;
    for (i = 0; i <= 100; i++) {
        printf("%d", i);
    }


## 1.4 Symbolic Constants ##
Define a symbolic constant to give a sequence of characters a meaningful name.  
`#define NAME replacement_text` to create the constant.  


## 1.5 Character Input and Output ##
The Standard Library text model assumes text input is a stream of characters.
This stream is 0 or more characters followed by a newline.  
`getchar` and `putchar` to go one char at a time.
Handle the return value as an `int` so the `EOF` constant is accepted.  

`++` and `--` to increment and decrement, either pre- or postfix.

Single-quotes denote a character constant and are the integer equivalent of a letter.
Double-quotes create a string-literal.


## 1.6 Arrays ##
`int digit_array[10]`.  
Remember that chars are just ints.


## 1.7 Functions ##
Functions encapsulate some computation.
Declare a function prototype by writing it's return type, name, and typed parameters:

    int power(int m, int n);

If there are no params, put `void` for compatibility.


## 1.8 Arguments - Call by Value ##
All function arguments are passed by value.  
In other words, a function is given the values in temp variables, not the originals.  
A called function cannot directly alter the arguments given to it.  
To modify an argument, pass a pointer to it.  


## 1.9 Character Arrays
Char arrays are always terminated by `\0`.  
A char array can be modified by a function when passed as a parameter.


## 1.10 External Variables and Scope ##
Automatic, or local, variables exist only in the function in which they are declared.
When that function exits they cease to exist.

Braces act as a naming scope , not a stack frame. Compilers may optimize variables away, however, if they are inside a scope without control.

**external** variables are global accessible.
They must be defined once outside of any functions.
Then they must be declared in each function wanting access using `extern`.
Note that this extra declaration is only necessary if the function comes before the variable definition.

For multi-file programs, put external variable definitions in a header file.

Exercises and examples appear in their own files.
