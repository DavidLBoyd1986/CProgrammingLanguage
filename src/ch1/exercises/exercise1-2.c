#include <stdio.h>

main() {

	// This won't compile due to "unknown escape sequence: \l"
	printf("hello, world!\l");
	return 0;
}
