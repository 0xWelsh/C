#include <stdio.h>
#include <stdlib.h>

char *gets(char *s);

void gadget() {
	// this is a hint for our lab to make finding the string easier
	char *sh = "/bin/sh";
}

void vuln() {
	char buffer[16];
	printf("Give me your name: ");
	gets(buffer);
}

int main() {
	vuln();
	return 0;
}
