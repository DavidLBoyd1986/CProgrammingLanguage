#include <stdlib.h>
#include <stdio.h>

char* get_secret_letter(int id)
{
	char* secret_letter = (char *)malloc(sizeof(char));

	*secret_letter = 'W';

	return secret_letter;
}

int main()
{
	char* secret_letter = get_secret_letter(85);

	printf("Secret letter is: %c\n", *secret_letter);

	free(secret_letter);

	printf("(Security risk!) Memory still around %p\n", secret_letter);
	printf("(Security risk!) Secret letter still accessible: %c\n", *secret_letter);
	// The second print has NOT matched the original data.
	// But should re-initialize pointers to NULL to sanitize data
	
	secret_letter = NULL; // zero out the pointer

	// Doing the above also throws error if trying to dereference NULL pointer
	printf("Cannot access the memory anymore %p\n", secret_letter);

	return EXIT_SUCCESS;
}
