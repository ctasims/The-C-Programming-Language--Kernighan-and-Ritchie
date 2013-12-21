# Chapter 2: Types, Operators and Expressions
Pages 35 - 54, 10 Exercises  

## Summary
2.1 Variable names can have letters, numbers and _.  
2.2 `int`, `char`, `float`, `double`. `short` and `long`, implementation-specific.  
2.3 String and char constants, enumerations.  
2.4 Declaring and initializing variables. `const`.   
2.5 Operators and precedence. The behavior of `%` and truncation.  
2.6 Logical operator precedence and behavior.  
2.7 converting narrow -> wide are automatic. `ctype.c` library.  
2.8 ++ and -- prefix augment before use; postfix augments after use.   
2.9 `>>`, `<<`, `&`, `|` and `~` bit operators.  
2.10 Most binary operators can be used as assignment operator.  
2.11 `expr1 ? T->expr2 : F->expr3`  
2.12 Do NOT write code that depends on order of evaluation!  

## Exercises
1. Done. Not sure how to compute values.
2. Done.
3. Done. Had trouble with types and two-sided logic operators. Used minor optimizations from solutions online (defining funcs). 
4. Done.
5. Done. 
6. Done.
7. Done.
8. Done. Struggled with how far to left-shift wraparound. Looked at solutions for help but they didn't. Cheated(?) by using `sizeof`.
9. Done.
10. Done. Easy. 


## 2.1 Variable Names
Comprised of letters, digits and _. First char must be letter.


## 2.2 Data Types and Sizes
`char` holds a single character in one byte.  
`int` represents an integer and reflects the natural int size.  
`short` and `long` to alter `int` length.  
`float` is single-precision.  
`double` is double-precision.  
`(unsigned)` to typecast to `unsigned int`.  
`signed` or `unsigned` for `chars` and `ints`.  


## 2.3 Constants
Use suffixes to specify `float` (f), `long` (l, L).  
`0` for octal, `0x` or `0X` for hex integers.  
The machine character set determines the actual integer value of a `char`.  
`'\000'` to specify an octal byte.  
`\xhh` to specify a hex byte.  

    \#define VTAB `\013`
    \#define VTAB `\xb`

`'\0'` for the null character representing value 0.

**Constant Expressions** contain only constants and are evaluated during compilation:

    #define MAXLINE 1000
    char line[MAXLINE+1];

String constants are concatenated at compile time:

    "Hello " "world!"

Strings are terminated with the null character.
`strlen(x)` from `string.h` to get a string's length, not including the null.

Use **enumerations** to define a list of constant integer values:

    enum boolean { NO, YES };

The value defaults to 0 increasing, or can be set manually.

### Enumeration constants
Enums can be more convenient than `define` because their values are generated.
Their values can also be checked by the compiler for validation.

    enum escapes { BELL = '\a', BACKSPACE = '\b', TAB = '\t' };
    enum months {JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };


## 2.4 Declarations
Declare variables by specifying their type, and optionally, a value.  
`const` for a constant value.  


## 2.5 Arithmetic Operators
Machine-dependent:
* The direction of truncation with `/`.
* sign of result of `%` for negative operands.

## 2.6 Relational and Logical Operators
Mostly review.  
The numeric value of a relational or logical expression is 1 if true, 0 if false.  
Use `(!valid)` instead of `(valid == 0)` in most cases.  


## 2.7 Type Conversions
"Narrower" operands are converted into "broader"; e.g. `float + int = float`.  
Use the `ctype` library for portable tests and conversions of type.  
Whether a `char` becomes positive or negative when converted to an `int` is machine-dependent.
Note that characters from the std char set are always positive.  

Comparisons between signed and unsigned operands are machine-dependent.

During assignment the resulting value of the RHS is converted to that of the LHS.

Explicit conversion:

    (type-name) expression

Use automatic coercion to ensure function parameters are of the correct type.
Do this by specifying type conversion in function header:

    sqrt((double) n);


## 2.8 Increment and Decrement Operators
`++` and `--` can be used both prefix and postfix.
Prefix augments the value and then uses it.
Postfix uses the value and then augments it.
So `j = i++` sets `j` to the previous value of `i`, then increments `i`.

## 2.9 Bitwise Operators
Operators:

    &     AND
    |     OR
    ^     XOR
    <<    left shift
    >>    right shift
    ~     complement

Straightforward review. Some helpers:
* `&` to mask off bits.  
* `|` to turn bits on.
* `^ 0xff` to toggle.
* `<<` to multiply by 2's.
* `>>` to divide by 2's.
* `>>` a `signed` value will fill it with `signed` bits.


## 2.10 Assignment Operators and Expressions
Most binary operators can be used as assignment operators:

    expr1 op= expr2

`expr1` is only evaluated once.


## 2.11 Conditional Expressions
Use conditional expressions to condense `if-else` logic:

    expr1 ? (T) expr2 : (F) expr3


## 2.12 Precedence and Order of Evaluation
Do NOT write code that depends on order of evaluation!  
Always be aware of side effects!
