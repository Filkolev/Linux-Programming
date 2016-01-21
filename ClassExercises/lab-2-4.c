#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10000
#define START 2
#define EMPTY -1

int main() {
	int numbers[MAX - START + 1];
	int i;
	for (i = START; i <= MAX; i++) {
		numbers[i - START] = i;
	}

	for(i = 0; i <= MAX - START; i++) {
		if (numbers[i] == EMPTY) {
			continue;
		}			
		
		int j;
		for (j = numbers[i] + numbers[i]; j <= MAX - START; j += numbers[i]) {
			numbers[j] = EMPTY;
		}
	}

	for (i = 0; i <= MAX - START; i++) {
		if (numbers[i] != EMPTY) {
			printf("%d ", numbers[i]);
		}
	}

	return EXIT_SUCCESS;
}
