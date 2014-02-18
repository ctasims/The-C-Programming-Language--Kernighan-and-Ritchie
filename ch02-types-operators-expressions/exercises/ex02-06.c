/*
 * Exercise 2-6: 
 * Write function that returns x with the n bits that begin at position p set to the rightmost n bits of y, leaving the other bits unchanged.
 */
#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    /* Strategy:
     * Think of bits in three sections: | x x x | y y y | x x x
     *      first part of x, unchanged
     *      second part of x, which will be replaced by section of y
     *      third part of x, unchanged
     * 1. Just mask off sections 2 and 3.
     * 2. mask off everything but correct section in y.
     * 3. Mask off sections 1 and 2.
     * the left and right shift of y drops all bits we don't want.
     * Then shift that over p-n spots so it aligns with correct position in x.
     */
    return (x & (~0 << p + 1)) | (y & ~(~0 << n)) << (p+1-n) | (x & ~(~0 << (p + 1- n)));
}

/* From K & R. */
unsigned getbits(unsigned x, int p, int n)
{
   return (x >>(p+1-n)) & ~(~0 << n);
}

/*
 * Display number as bits.
 * Taken from http://clc-wiki.net/wiki/K%26R2_solutions:Chapter_2:Exercise_6.
 * Written by Pilcrow.
 */
void asbits(unsigned x, size_t s, int nl)
{
	int i;

	for(i = s*8-1; i>=0; i--) {
		 getbits(x, i, 1)? putchar('1') : putchar('0');
		 if(!(i%4))putchar(' ');
	}
	if(nl)putchar('\n');
}

int main() {
    int offset = 27;
    int len = 7;
    unsigned x = 0x12345678;
    unsigned y = 0xffffffff;
    asbits(x, sizeof(x), 1);
    asbits(y, sizeof(x), 1);
    asbits(setbits(x, offset, len, y), sizeof(x), 1);
    return 0;
}
