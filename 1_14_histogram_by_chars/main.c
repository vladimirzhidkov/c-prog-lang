#include <stdio.h>

#define SPACE	32
#define DEL		127
#define SIZE	(DEL - SPACE)

// prints a histogram of the frequencies of different characters in input.
int main() {
	int histogram[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		histogram[i] = 0;
	}

	int c;
	while ((c = getchar()) != EOF) {
		if (c >= SPACE && c < DEL) {
			++histogram[c - SPACE];
		}			
	}

	for (int i = SPACE; i < DEL; ++i) {
		printf("%c: ", i);
		for (int j = 0; j < histogram[i - SPACE]; ++j) {
			putchar('*');
		}
		putchar('\n');	
	}

	return 0;
}
