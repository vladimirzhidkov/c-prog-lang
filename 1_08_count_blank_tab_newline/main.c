#include <stdio.h>

// counts blanks, tabs, and newlines.
int main() {
	int c;
	int count = 0;
	while ((c = getchar()) != EOF) {
		if ( c == ' ' || c == '\t' || c == '\n') {
			++count;
		}
	}
	printf("count: %d\n", count);
	return 0;
}
