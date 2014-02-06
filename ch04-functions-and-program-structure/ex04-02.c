/*
 * Exercise 04-02.
 * Extend atof to handle scientific notation.
 */

#include <ctype.h>

/* atof: convert string s to double */
double atof(char s[])
{
    double val, power, naive_val, exponent;
    int i, sign, exp_sign, exp_val;

    for (i = 0; isspace(s[i]); i++)     /* skip whitespace */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    /* check for scientific notation */
    if (s[i] == 'e' || s[i] == 'E') {
        i++;
        val = sign * val / power;
        /*  get exponent sign */
        exp_sign = (s[i] == '-') ? -1 : 1;
        if (s[i] == '+' || s[i] == '-')
            i++;
        /* get exponent as double */
        for (exp_val = 0; isdigit(s[i]); i++)
            exp_val = 10 * exp_val + (s[i] - '0');
        /* apply exponent to base number */
        for (i=0; i <= exp_val; i++)
            if (exp_sign)
                val *= 10;
            else
                val /= 10;
        return val;

    } else
        return sign * val / power;
}
