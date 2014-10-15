/*
 * =====================================================================================
 *
 *       Filename:  ex01-19-v2.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/15/2014 
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Carlos A. Fajardo, cafajar@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
 
 #include <stdio.h>
#include <string.h>

int readline(char line[]);
void reverse(char s[]); 



int main()
{
#define N 200
#define MAX 15

char line[N];


int i;
for (i=0; i < N; i++)
	salida[i]='\0';
	
printf("---- Exercise 1-19 ------\n");

readline(line);
printf("Shift the message...  \n \n");

reverse(line);

printf("%s \n", line);
return 0;

}

int readline(char s[]){
int i=0;
int c;

	while ((c = getchar()) != '\n' )
	{ s[i]=c;
		++i;
	}  
	s[i]='\0';
	return i;
}


/* reverse string in-place */
void reverse(char s[])
{
    int len = strlen(s); 
    int j;
	char temp;
	char temp2[2];

    /* copy it back into s, in reverse order */
    j = 0;
    while (len > j) {
        temp = s[j];
		s[j] = s[len-1];
		s[len-1]=temp;
        --len;
        ++j;
    }
}

