#include <stdio.h>

int main(void)
{

	puts("Printable ASCII:");
	for (int i = 32; i < 127; ++1) {
	
		putchar(i);
		putchar(i % 16 == 15 ? '\n' : ' ');
	}
}
