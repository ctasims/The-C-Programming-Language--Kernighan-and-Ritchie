# Chapter 5: Pointers and Function Arguments

## Summary
1. Pointer variables hold addresses of variables or array elements.
2. C calls by value so use pointers to access and modify things in the calling function.
3. Array variables and pointers are similar; an array-and-index expression are equivalent to pointer-and-offset expression.
4. We can add/subtract pointers in same array, or with integers.
5. Character pointers provide several benefits over arrays when dealing with strings.
6. Match the data structure with the need. Arrays of pointers can solve many
   problems.
7. 
8. 
9. 
10. 
11. 
12. 


## 5.1


## 5.2


## 5.3


## 5.4


## 5.5


## 5.6


## 5.7 Multi-dimensional Arrays
Often better to use arrays of pointers instead of multi-dimensional arrays.
We declare md arrays with nested `{}`.
Note that when referencing an element, use the notation `array[x][y]`, not
`array[x,y]` because arrays are really arrays of arrays.

When passing md array to a function, we must tell how many columns it has.

    int f(int daytab[][13]...)

    int f (int (*daytab)[13]


## 5.8 Initialization of Pointer Arrays
Simple example of simple concept.


## 5.9 Pointers vs. Multi-dimensional Arrays
Arrays of pointers can have rows with different numbers of columns (different lengths of arrays being pointed to).
Great for storing character strings.


## 5.10 Command-line Arguments
`argc` is the count of passed arguments.
`argv` is the argument vector - a pointer to an array of character strings which are the arguments passed by the user.
The first entry is the program name.
