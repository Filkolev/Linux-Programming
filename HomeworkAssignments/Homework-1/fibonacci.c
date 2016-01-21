#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 25
#define BASE_OF_NUMERAL_SYSTEM 10

void get_max_fibonacci(int fib_1[MAX_DIGITS], int fib_2[MAX_DIGITS], int fib_n[MAX_DIGITS]);

int main() {
	int fib_1[MAX_DIGITS] = {0};
	int fib_2[MAX_DIGITS] = {0};
	int fib_n[MAX_DIGITS] = {0};

	fib_2[MAX_DIGITS - 1] = 1;
	get_max_fibonacci(fib_1, fib_2, fib_n);
	
	int i;
	for (i = MAX_DIGITS - 1; i >= 0; i--) {
		printf("%d", fib_n[i]);
	}

	printf("\n");
	
	return EXIT_SUCCESS;
}

void get_max_fibonacci(int fib_1[MAX_DIGITS], int fib_2[MAX_DIGITS], int fib_n[MAX_DIGITS]) {
	int last_position = MAX_DIGITS - 1;
	
	while(last_position >= 0) {
		int carry = 0;
		int position = MAX_DIGITS - 1;
		
		for (;position > last_position; position--) {
			int sum = fib_1[position] + fib_2[position] + carry;
			fib_n[position] = sum % BASE_OF_NUMERAL_SYSTEM;
			carry = sum / BASE_OF_NUMERAL_SYSTEM;
		}

		while (carry > 0) {
			fib_n[position] = carry % BASE_OF_NUMERAL_SYSTEM;
			carry /= BASE_OF_NUMERAL_SYSTEM;
			position--;	
		}

		fib_1 = fib_2;
		fib_2 = fib_n;
		
		int i;
		for (i = 0; i < MAX_DIGITS; i++) {
			fib_n[i] = 0;
		}
		
		last_position = position;
	}
}
