#include <stdio.h>
/*
 C-style comments can contain multiple lines
 */

/* or, just one line. */

// C++ style comments can comment one line.

// or, they can
// be strung together


int main(void)
{

	//the below code won't be run
	//puts("Hello");
	
	// The below code will be run
	puts("World");

	// a note regarding backslash + newline.
	// despite belonging to translation phase 2 (vs phase 3 for comments).
	// '\' still determines which portion of the source code is considered
	// as 'comments':
	// this comment will be promoted to the next line \
	puts("Won't be run"); //may issue a warning "multi-line comment"
	puts("Hello, again");
}
