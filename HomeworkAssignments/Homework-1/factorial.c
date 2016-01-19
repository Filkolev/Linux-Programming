/*
 * Factorial calculated using an auxiliary array of chars
 * See: https://en.wikipedia.org/wiki/Arbitrary_precision_arithmetic
 */

#include <stdio.h>
#include <stdlib.h>

#define BASE_OF_NUMERAL_SYSTEM 10
#define MAX_FACTORIAL 100

/*
 * Number of digits precalculated for 100!
 * See: https://math.stackexchange.com/questions/1075422/how-many-digits-are-there-in-100
 */
#define MAX_DIGITS 158

int main() {
	char result_text[MAX_DIGITS + 1];
	int i;
	for (i = 0; i < MAX_DIGITS; i++) {
		result_text[i] = ' ';
	}

	const char digits[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	
	// the result represented by an array of digits
	int result_digits[MAX_DIGITS + 1];
	result_digits[0] = 1;
	for (i = 1; i <= MAX_DIGITS; i++) {
		result_digits[i] = 0;
	}

	int last_position = 1;
	int number;
	for (number = 1; number <= MAX_FACTORIAL; number++) {
		int carry = 0;

		int current_position;
		for (current_position = 0; current_position < last_position; current_position++) {
			int digit_value = result_digits[current_position] * number + carry;
			result_digits[current_position] = digit_value % BASE_OF_NUMERAL_SYSTEM;
			carry = digit_value / BASE_OF_NUMERAL_SYSTEM;
		}

		while (carry > 0) {
			if (last_position >= MAX_DIGITS) {
				printf("Overflow");
				return EXIT_FAILURE;
			}

			result_digits[last_position] = carry % BASE_OF_NUMERAL_SYSTEM;
			last_position++;
			carry /= BASE_OF_NUMERAL_SYSTEM;
		}

		for (current_position = 0; current_position < last_position; current_position++) {
			int index = result_digits[current_position];
			char current_digit = digits[index];
			result_text[MAX_DIGITS - current_position] = current_digit;
		}

		int offset = 0;
		while (result_text[offset] == ' ') {
			offset++;
		}

		printf("%d! = %s\n", number, result_text + offset);
	} 

	return EXIT_SUCCESS;	
}
