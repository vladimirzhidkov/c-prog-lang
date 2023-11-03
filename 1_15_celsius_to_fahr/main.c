#include <stdio.h>

float celsius_to_fahr(int celsius); 

int main() {
	int celsius;
	int lower;
	int upper;
	int step;

	lower = -100;
	upper = 100;
	step = 10;

	printf("Celsius-Fahrenheit table:\n");
	for (celsius = upper; celsius >= lower; celsius = celsius - step) {
		printf("%3d\t%6.1f\n", celsius, celsius_to_fahr(celsius));
	}
	
	return 0;
}

float celsius_to_fahr(int celsius) {
	return 9.0 /5.0 * celsius + 32.0;
}
