#include <stdio.h>
#include <stdlib.h>

int main() {
	char *first_name;
	char *last_name;

	scanf("%ms %ms", &first_name, &last_name);
	printf("%s, %s\n", last_name, first_name);

	free(first_name);
	free(last_name);

	return 0;
}
