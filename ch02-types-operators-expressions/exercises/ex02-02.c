/*
 * Exercise 2-2:
 * Write a loop equivalent to the following loop without using && and ||
 *
 * for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i)
 *      s[i] = c;
 *
 * We'll just use if statements to check for the latter conditions.
 * This can easily be turned into a while-loop as well.
 */
int main() {
    int i;
    for (i=0; i < lim-1; ++i) {
        if ((c = getchar()) != '\n') {
            if (c != EOF) {
                s[i] = c;
            }
        }
    }
}
