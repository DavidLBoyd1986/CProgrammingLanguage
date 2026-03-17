#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 5000
#define MAXLEN 5000
#define ALLOCSIZE 50000

char *lineptr_array[MAX_LINES];

int get_line(char *, int, FILE *);
char *alloc(int);

int main(int argc, char *argv[MAX_LINES])
{
	long int num_of_lines = 10;
	FILE *input_ptr;
	char *endptr;

	if (argc > 1) {
		for (int a = 1; a < argc; a++) {
			if (strcmp(argv[a], "-n") == 0) {
				num_of_lines = strtol(argv[++a], &endptr, 10);
			} else if (argv[a][0] != '-') {
				input_ptr = fopen(argv[a], "r");
			} else {
				printf("Invalid argument: %s\n", argv[a]);
				return EXIT_FAILURE;
			}
		}
	}
	
	char c;
	char *temp_p;
	char line[MAXLEN];
	int i, n, nlines;
	nlines = 0;

	// Pass line into get_line to read a line. THIS MIGHT NEED MOVED INTO MAIN LOOP
	for (i = 0; (n = get_line(line, MAXLEN, input_ptr)) > 0; i++) {
		// alloc the space for the string and get a pointer to it
		if ((nlines > MAX_LINES) || (temp_p = alloc(n)) == NULL) {
			return -1;
		} else {
			line[n-1] = '\0'; /* delete '\n' */
			strcpy(temp_p, line); /* Copy line to alloc string */
			lineptr_array[i] = temp_p;
			nlines++;
		}
	}

	for (int i = 0; i < num_of_lines; i++) {
		printf("%s\n", lineptr_array[i]);
	}
}

static char allocbuf[ALLOCSIZE];	/* storage for alloc */
static char *allocp = allocbuf;

int get_line(char s[], int lim, FILE *fptr)
{
	int i, c;
	int debug = 0;

	for (i = 0; i < lim - 1 && (c = fgetc(fptr)) != EOF && c != '\n'; ++i)
		s[i] = c;
		debug++;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	if (c == EOF)
		return 0;
	s[i] = '\0';
	return i;
}

char *alloc(int n)
{
	if (allocbuf + ALLOCSIZE - allocp >= n) {	/* it fits */
		allocp += n;
		return allocp - n; /* old p */
	} else {
		return 0;
	}
}

/* afree: free storage pointed to by p */
void afree(char *p)
{
	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
