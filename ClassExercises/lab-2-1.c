#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 30

int main() {
	char first_name[NAME_SIZE];
	char last_name[NAME_SIZE];
	memset(first_name, 0, NAME_SIZE);
	memset(last_name, 0, NAME_SIZE);
	
	printf("Please enter your first and last name separated by space: ");
	scanf("%s %s", &first_name, &last_name);

	printf("%s, %s\n", last_name, first_name);

	return EXIT_SUCCESS;
}
