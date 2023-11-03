#include <stdio.h>

#define IN	0
#define OUT	1

/* prints its input one word per line */
int main() {
	int c;
	int state = OUT;
	while ((c = getchar()) != EOF) {
		// inside word
		if (c != '\n' && c != '\t' && c != ' ') {
			state = IN;
			putchar(c);
		// transitioning from INside into OUTside of the word
		} else if (state == IN) {
			putchar('\n');
			state = OUT;
		}
	}

	return 0;
}
