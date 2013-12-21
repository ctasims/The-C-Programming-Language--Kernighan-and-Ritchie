/*
 * Exercise 2-7:
 * Write a function that returns x with n bits at position p inverted.
 */

#include <stdio.h>

unsigned invert(unsigned x, int p, int n)
{
    /* Do this one in three sections as well: | 1 1 1 | 2 2 2 | 3 3 3|
     * 1: just copy from x
     * 3: copy from x
     * 2: tricky part. shift this part to right, then XOR it, then shift back.
     */
    return (x & (~0 << p+1)) | (~(~0 << n) ^ (~(~0 << n) & (x >> (p+1-n)))) << (p+1-n) | (x & ~(~0 << (p+1-n)));
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
    asbits(x, sizeof(x), 1);
    asbits(invert(x, offset, len), sizeof(x), 1);
    return 0;
}
