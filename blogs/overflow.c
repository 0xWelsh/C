#include <stdio.h>
#include <string.h>

char *gets(char *s);

void secret_function() {
	printf("Execution Hijacked!\n");
	}
	
void vuln_input(){
	char buffer[16]; // the bucket
	printf("Enter input: ");
	gets(buffer); // the hose
	}
	
	int main() {
		vuln_input();
		return 0;
		}
		
		
