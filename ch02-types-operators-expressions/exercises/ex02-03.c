/*
 * Write the function htoi(s), which converts a string of hex digits (including the optional 0x or 0X) into its equivalent integer value.
 * The allowable digits are 0 through 9, a though f, and A through F.
 */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
/* I got these from solution page. Pilcrow's. Didn't know I could define funcs here! */
#define HEX_LO(N) ( (N) >= 'a' && (N) <= 'f')
#define HEX_HI(N) ( (N) >= 'A' && (N) <= 'F')
#define HEX_NUM(N) ( (N) >= '0' && (N) <= '9')

unsigned long htoi(char hex_num[]);

int main() {
    char hex1[] = "1D9";
    char hex2[] = "DEADBEEF";
    char hex3[] = "0X123456";
    /*int hex1_val = htoi(hex1);*/
    printf("%s -> %u\n\n", hex1, htoi(hex1));  /* 473 */
    printf("%s -> %u\n\n", hex2, htoi(hex2));  /* 3735928559 */
    printf("%s -> %u\n\n", hex3, htoi(hex3));  /* 1193046 */
}

/*
 * Convert hex value into integer form.
 */
unsigned long htoi(char hex_num[]) {
    int val = 0, index = 0, hex_len;
    char c;
    long total = 0;

    hex_len = strlen(hex_num) - 1;

    /* Check for optional 0x or 0X. */
    if (hex_num[0] == '0' && (hex_num[1] == 'x' || hex_num[1] == 'X'))
        index = 2;

    while ((c=hex_num[index]) != '\0') {
        if (HEX_NUM(c))
            total += pow(16, hex_len - index) * (c - '0');
        else if (HEX_LO(c))
            total += ((int) pow(16, hex_len - index)) * (10 + c - 'a');
        else if (HEX_HI(c))
            total += ((int) pow(16, hex_len - index)) * (10 + c - 'A');
        ++index;
    }
    return total;
}
