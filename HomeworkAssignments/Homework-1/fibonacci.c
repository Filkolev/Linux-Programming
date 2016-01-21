#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DIGITS 25
#define BASE_OF_NUMERAL_SYSTEM 10

/*
 * The largest Fibonacci number with 25 digits, assuming series starts with 1 (not 0)
 */
#define MAX_FIBONACCI 120

void get_max_fibonacci(int fib_1[MAX_DIGITS], int fib_2[MAX_DIGITS], int fib_n[MAX_DIGITS]);

int main() {
	int fib_1[MAX_DIGITS] = {0};
	int fib_2[MAX_DIGITS] = {0};
	int fib_n[MAX_DIGITS] = {0};

	fib_1[MAX_DIGITS - 1] = 1;
	fib_2[MAX_DIGITS - 1] = 1;
	get_max_fibonacci(fib_1, fib_2, fib_n);
	
	char result[MAX_DIGITS + 1] = {0};	
	int i;
	for (i = 0; i < MAX_DIGITS; i++) {
		result[i] = fib_2[i] + '0';
	}

	char *file_name = strcat(result, ".txt");
	FILE *result_file = fopen(file_name, "w");
	fwrite(result, MAX_DIGITS, sizeof(char), result_file);
	fclose(result_file);
	
	return EXIT_SUCCESS;
}

void get_max_fibonacci(int fib_1[MAX_DIGITS], int fib_2[MAX_DIGITS], int fib_n[MAX_DIGITS]) {
	int fib_position;
	
	for (fib_position = 2; fib_position <= MAX_FIBONACCI; fib_position++) {
		int carry = 0;
		int position;
		
		for (position = MAX_DIGITS - 1; position >= 0; position--) {
			int sum = fib_1[position] + fib_2[position] + carry;
			fib_n[position] = sum % BASE_OF_NUMERAL_SYSTEM;
			carry = sum / BASE_OF_NUMERAL_SYSTEM;
		}

		while (carry > 0) {
			fib_n[position] = carry % BASE_OF_NUMERAL_SYSTEM;
			carry /= BASE_OF_NUMERAL_SYSTEM;
			position--;	
		}
		
		int i;
		for (i = 0; i < MAX_DIGITS; i++) {
			fib_1[i] = fib_2[i];
			fib_2[i] = fib_n[i];
			fib_n[i] = 0;
		}

	}
}
