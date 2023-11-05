#include <stdio.h>

#define IN	0
#define OUT	1
#define MAX_LENGTH 15

/* prints a histogram of the lengths of words in input */
int main() {

	/* initialize histogram */
	int histogram[MAX_LENGTH + 1];
	int i;
	for (i = 0; i <= MAX_LENGTH; ++i) {
		histogram[i] = 0;
	}

	/* count word lengths */
	int c;
	int word_length = 0;
	int state = OUT;
	while ((c = getchar()) != EOF) {
		/* inside */
		if (c != ' ' && c != '\n' && c != '\t') {
			state = IN;
			++word_length;
		}
		/* transitioning from inside into outside */
		else if (state == IN) {
			state = OUT;
			if (word_length <= MAX_LENGTH) {
				++histogram[word_length];
			}
			word_length = 0;
		} 
	}	
	
	/* print histogram */
	for (i = MAX_LENGTH; i > 0; --i) {
		printf("%2d: ", i);
		int j;
		for (j = 0; j < histogram[i]; ++j) {
			putchar('*');	
		}
		putchar('\n');
	}
	
	return 0;
}
