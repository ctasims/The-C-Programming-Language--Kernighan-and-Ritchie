/*
 * Exercise 4-9
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // for atof()
#include <ctype.h>
#include <math.h>

#define MAXOP   100  // max size of operand or operator
#define NUMBER  '0'  // signal that a number was found
#define COMMAND '1'  // signal that a command was found
/*#define FUNC    '2'  // signal that a function was found*/

#define MAXVAL  100  // max depth of val stack
#define BUFSIZE 100  //

int getop(char []);
void clear(void);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
void ungets(char []);
void ungets2(char []);

int sp = 0;         // next free stack position
double val[MAXVAL]; // value stack
char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       // next free position in buffer

// variables
double a, b, c, x, y, z;
int setting_var = 0;  // 1 if we're setting a variable. 0 otherwise.

/* reverse Polish calculator */
main()
{
    int type;
    double op2, op3;
    char s[MAXOP];
    char var_name;
    int var_int;

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case COMMAND:
                // identify and execute given command
                if (strcmp(s, "print") == 0) {
                    op2 = pop();
                    printf("\t%.8g\n", op2);
                    push(op2);
                } else if (strcmp(s, "dup") == 0) {
                    op2 = pop();
                    push(op2);
                    push(op2);
                } else if (strcmp(s, "swap") == 0) {
                    op2 = pop();
                    op3 = pop();
                    push(op2);
                    push(op3);
                } else if (strcmp(s, "clear") == 0) {
                    clear();
                } else if (strcmp(s, "sin") == 0) {
                    op2 = pop();
                    push(sin(op2));
                } else if (strcmp(s, "cos") == 0) {
                    op2 = pop();
                    push(cos(op2));
                } else if (strcmp(s, "exp") == 0) {
                    op2 = pop();
                    push(exp(op2));
                } else if (strcmp(s, "pow") == 0) {
                    op2 = pop();
                    push(pow(pop(), op2));
                } else if (strcmp(s, "set") == 0) {
                    // format to set a variable is set 4 a, which is a = 4
                    setting_var = 1;
                } else if (strcmp(s, "a") == 0) {
                    if (setting_var) {
                        a = pop();
                        setting_var = 0;
                    }
                    push(a);
                } else if (strcmp(s, "b") == 0) {
                    if (setting_var) {
                        b = pop();
                        setting_var = 0;
                    }
                    push(b);
                } else if (strcmp(s, "c") == 0) {
                    if (setting_var) {
                        c = pop();
                        setting_var = 0;
                    }
                    push(c);
                } else if (strcmp(s, "x") == 0) {
                    if (setting_var) {
                        b = pop();
                        setting_var = 0;
                    }
                    push(x);
                } else if (strcmp(s, "y") == 0) {
                    if (setting_var) {
                        y = pop();
                        setting_var = 0;
                    }
                    push(y);
                } else if (strcmp(s, "z") == 0) {
                    if (setting_var) {
                        z = pop();
                        setting_var = 0;
                    }
                    push(z);
                }
                break;
                
            case NUMBER:
                printf("%s, %f\n", s, atof(s));
                push(atof(s));
                break;
            case '%':
                op2 = (int) pop();
                push((int)pop() % (int)op2);
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("Error: cannot divide by 0\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

/* clear stack */
void clear(void)
{
    sp = 0;
    bufp = 0;
}


/* push: push f onto value stack */
void push(double f)
{
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, cannot push %g\n", f);
}

/* pop: pop and return top value from stack. */
double pop(void)
{
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}


/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;
    char word[10];

    // skip whitespace
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';

    // single char operator
    if (c == '%' || c == '+' || c == '/' || c == '\n' || c == '*') {
        return c;
    }

    i = 0;
    // '-' is a special case since it can signify negative number
    if (c == '-') {
        // need to determine if neg number or subtraction
        if ((c = getch()) == ' ' || c == '\t' || c == EOF || c == '\n') {
            // subtraction
            ungetch(c);
            return '-';
        } else // neg number
            ungetch(c);
    }

    if (!isdigit(c) && c != '.' && c != '-') {
        // variable or command so get entire thing
        while ((s[++i] = c = getch()) != ' ' && c != EOF && c != '\n' && c != '\t')
            ;
        s[i] = '\0';
        ungetch(c);
        return COMMAND;
    }

    if (isdigit(c))     // collect integer part
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') {     // collect fraction part
        while (isdigit(s[++i] = c = getch()))
            ;
    }
    s[i] = '\0';
    ungetch(c);
    return NUMBER;
}

/* getch: get a (possibly pushed back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/* push char back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else if (c != EOF)
        buf[bufp++] = c;
}

