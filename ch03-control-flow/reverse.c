
#include <string.h>

/*
 * reverses string in-place.
 */
void reverse(char s[]) {
    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}
