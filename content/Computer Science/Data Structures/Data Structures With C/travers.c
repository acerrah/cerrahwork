#include <stdio.h>

int main() {
	char str[15] = "Hello, World!";
	int i = 0;

	for (i = 0; i < sizeof(str); i++)
		printf("element %d: %c \n", i, str[i]);

	return 0;
}






