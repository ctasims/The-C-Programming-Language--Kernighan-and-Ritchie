/*
 * Exercise 3-4:
 * itoa does not handle the largest negative number: -2^(wordsize-1). Why not?
 * The required range of ints is: -2^15+1 to 2^15-1
 * In the line n = -n the number is converted to positive.
 * But in this case it's outside the bounds.
 *
 * e.g.
 * largest negative # (-128):   1000 0000
 * largest positive # (127):    0111 1111 
 *
 * I'm not sure what will happen when sign of -128 is flipped. Error?
 *
 * Modify itoa to print that value correctly, regardless of the machine it's on.
 * I think I can just change:
 *      while ((n /= 10) > 0)
 * to:
 *      while (n /= 10)
 *
 *  Since the int will truncate fractional parts and won't go negative.
 *  Currently it looks like it will break with the neg number, which can't be flipped to zero.
 */


/*  itoa: convert n to characters in s. Handles largest negative number. */
void itoa2(int n, char s[])
{
    int i, sign;

    if ((sign = n) < 0)     // record sign
        n = -n;             // make n positive
    i = 0;
    do {                        // generate digits in reverse order
        s[i++] = n % 10 + '0';  // get next digit
    } while (n /= 10);    // delete it
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}
