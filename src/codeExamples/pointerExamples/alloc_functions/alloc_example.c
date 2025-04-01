#include <stdio.h>
#include <stdlib.h>

#define ALLOCSIZE 10000 /* size of available space */

void afree(char *);	/* free storage pointed to by p */
char *alloc(int ); 	/* return pointer to n characters */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

int main()
{
	char *test1 = alloc(5);
	printf("\ntest1 address = %p\n", test1);
	char *test2 = alloc(15);
	printf("\ntest2 address = %p\n", test2);
	afree(test2);
	char *test3 = alloc(5);
	printf("\ntest3 address = %p\n", test3);
	char *test4 = alloc(15);
	printf("\ntest4 address = %p\n", test4);
}

char *alloc(int n) 	/* return pointer to n characters */
{
	if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
		allocp += n;
		return allocp - n; /* old p */
	} else { /* not enough room */
		return 0;
	}
}

void afree(char *p)	/* free storage pointed to by p */
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}

