/*
 * Exercise 5-10
 */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MAXOPS 100
#define OPERATOR 1

double buffer[MAXOPS];
int bufp = 0;  // index of buffer; always points to next empty spot.

double pop(void);
void push(double);


int main(int argc, char *argv[]) {
    double op1, op2;
    char c;
    char arg;

    while (argc-- > 1) {
        // process the next arg
        *argv++;
        if (isdigit(c = **argv)) {
            push(atof(*argv));

        } else {
            printf("%c\n", c);
            switch (c) {
                case '+':
                    push(pop() + pop());
                    break;
                case '*':
                    push(pop() * pop());
                    break;
                case '/':
                    op2 = pop();
                    push(pop() / op2);
                    break;
                case '-':
                    op2 = pop();
                    push(pop() - op2);
                    break;
                default:
                    printf("op not recognized\n");
                    break;
            }
        }
    }
    printf("%.8g\n", pop());
}

double pop(void) {
    if (bufp == 0) {
        printf("Buffer empty\n");
        return -1;
    } else
        return buffer[--bufp];
}

void push(double n) {
    if (bufp == MAXOPS)
        printf("Buffer full\n");
    else
        buffer[bufp++] = n;
}

