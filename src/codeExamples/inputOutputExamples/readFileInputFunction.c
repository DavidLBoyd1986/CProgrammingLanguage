#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 5000
#define MAXLEN 500
#define ALLOCSIZE 50000

char *line_ptr[MAXLINES]; 	/* pointers to text lines */

int get_line(char *, int, FILE *);
int read_lines(FILE *, char *[]);
void write_lines(char *lineptr[], int nlines);
void my_qsort(void *lineptr[], int left, int right,
	   int (* comp)(void *, void *));
void swap(void *v[], int, int);
int numcmp(const char *, const char*);

/* sort input lines */
int main(int argc, char *argv[])
{
	int nlines;		/* number of input lines read */
	int numeric = 0;	/* 1 if numeric sort */
	FILE *input_ptr;	/* pointer to input FILE */

        if (argc > 1) {
                for (int a = 1; a < argc; a++) {
                        if (strcmp(argv[a], "-n") == 0) {
                                numeric = 1;
                        } else if (argv[a][0] != '-') {
                                input_ptr = fopen(argv[a], "r");
                        } else {
                                printf("Invalid argument: %s\n", argv[a]);
                                return EXIT_FAILURE;
                        }
                }
        }

	if ((nlines = read_lines(input_ptr, line_ptr)) >= 0) {
		my_qsort((void **) line_ptr, 0, nlines - 1,
			(int (*)(void*,void*))(numeric ? numcmp : strcmp));
		write_lines(line_ptr, nlines);
		return 0;
	} else {
		printf("input too bug to sort\n");
		return 1;
	}
}

int read_lines(FILE *input_ptr, char *line_ptr[])
{
	char c;
	char *temp_p;
	char line[MAXLEN];
	int i, n, nlines;
	nlines = 0;

	// Pass line into get_line to read a line. THIS MIGHT NEED MOVED INTO MAIN LOOP
        for (i = 0; (n = get_line(line, MAXLEN, input_ptr)) > 0; i++) {
                // alloc the space for the string and get a pointer to it
                if ((nlines > MAXLINES) || (temp_p = malloc(MAXLEN)) == NULL) {
                        return -1;
                } else {
                        line[n-1] = '\0'; /* delete '\n' */
                        strcpy(temp_p, line); /* Copy line to alloc string */
                        line_ptr[i] = temp_p;
                        nlines++;
                }
        }
	return nlines;
}

void write_lines(char *line_ptr[], int nlines)
{
	for (int i = 0; i < nlines; i++) {
		printf("%s\n", line_ptr[i]);
	}
}

void swap(void *v[], int i, int j)
{
	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/* numcmp: compare s1 and s2 numerically */
int numcmp(const char *s1, const char *s2)
{
	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

/* my_qsort: sort v[left]...v[right] into increasing order */
void my_qsort(void *v[], int left, int right,
	   int (*comp)(void *, void *))
{
	int i, last;

	if (left >= right)	/* do nothing if array contains */
		return;		/* fewer than two elements */
	swap(v, left, (left + right)/2);
	last = left;
	for (i = left+1; i <= right; i++)
		if ((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	my_qsort(v, left, last-1, comp);
	my_qsort(v, last+1, right, comp);
}

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

