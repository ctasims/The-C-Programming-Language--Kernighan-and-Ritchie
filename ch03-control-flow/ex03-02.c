/*
 * Exercise 3-2:
 * Write function that converts chars like newline and tab into visible escape sequences.
 * Use a switch statement.
 * Then write the reverse.
 */

#include <stdio.h>
#include <string.h>

void escape(char s[], char t[]);
void unescape(char s[], char t[]);

int main()
{
    char str1[100] = "Test new string\twith tabs\tand \n.";
    char str2[100];

    escape(str2, str1);
    printf("%s\n%s\n\n", str1, str2);

    unescape(str1, str2);
    printf("%s\n\n", str1);
    return 0;
}


void escape(char s[], char t[])
{
    int i = 0, j = 0;

    while (t[i]) {
        switch (t[i]) {
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            case '\b':
                s[j++] = '\\';
                s[j++] = 'b';
                break;
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\f':
                s[j++] = '\\';
                s[j++] = 'f';
                break;
            case '\v':
                s[j++] = '\\';
                s[j++] = 'v';
                break;
            case '\r':
                s[j++] = '\\';
                s[j++] = 'r';
                break;
            case '\"':
                s[j++] = '\\';
                s[j++] = '"';
                break;
            default:
                s[j++] = t[i];
                break;
        }
        ++i;
    }
    s[j] = t[i];
}


void unescape(char s[], char t[])
{
    int i, j;
    i = j = 0;

    while (t[i]) {
        if (t[i] == '\\') {
            switch (t[i+1]) {
                case 't':
                    s[j++] = '\t';
                    break;
                case 'b':
                    s[j++] = '\b';
                    break;
                case 'n':
                    s[j++] = '\n';
                    break;
                case 'f':
                    s[j++] = '\f';
                    break;
                case 'v':
                    s[j++] = '\v';
                    break;
                case 'r':
                    s[j++] = '\r';
                    break;
                case '"':
                    s[j++] = '\"';
                    break;
                default:
                    s[j++] = t[i];
                    break;
            }
            i++;
        } else
            s[j++] = t[i];

        i++;
    }
}
