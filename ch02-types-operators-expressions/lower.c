/*
 * Convert an uppercase letter to lowercase.
 * If the letter is not uppercase, return it.
 */
int lower(char c) {
    if (c => 'A' && c <= 'Z')
        return (c - 'A') + 'a';
    else
        return c;
}
