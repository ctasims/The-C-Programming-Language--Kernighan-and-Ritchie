/*
 * Exercise 2-9: In a two's complement number system, x &= (x-1) deletes the rightmost 1-bit in x.
 * Explain why.
 * Use this observation to write a faster version of bitcount.
 */

/*
 * Explanation:
 * Two cases: x is odd (right-most bit is 1) or x is even (right-most bit is 0).
 * If odd, x - 1 sets that bit to 0.
 * Then when we AND this with x, we get everything but the last bit.
 * e.g.: 5 is 0101. 5-1=4 is 0100. 0100 & 0101 yields 0100.
 *
 * If even:
 * 4: 0100, 3: 0011 -> 0100 & 0011 = 0000
 * 6: 0110, 5: 0101 -> 0110 & 0101 = 0100 == 4
 * So (x-1) sets right-most zeros to 1 and right-most 1 to 0.
 * ANDing these means we AND the right-most 1 with a 0, yielding a 0.
 */

/*
 * bitcount: count number of 1 bits in number.
 * Faster because # iterations == # 1 bits.
 */
int bitcount(unsigned x)
{
    int b;
    for (b = 0; x != 0; x &= (x-1))
        b++;
    return b;
}

int main()
{
}
