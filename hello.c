/*
 * =====================================================================================
 *
 *       Filename:  hello.c
 *
 *    Description:  Hello world!
 *
 *        Version:  1.0
 *        Created:  7/25/2013 11:58:09 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Cianan Sims (ctasims@gmail.com), 
 *   Organization:  
 *
 * =====================================================================================
 */

// include info about the standard i/o library.
// Header files tell us how to do/call something, whereas the actual library/implementation contains the functionality.
// One benefit: can change the library without having to alter my code.
// Header is the INTERFACE.
// Library is the IMPLEMENTATION.
#include <stdio.h>

// Every program must have a main somewhere.
main() {
    printf("Hello, beautiful!\e");
}

// 1-1 altered 'main', removed semicolon, changed printf.
// All errors are understandable.

// 1-2 Resulted in different symbols being printed. I like \r.
