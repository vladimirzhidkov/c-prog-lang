#include <stdio.h>
#define BLANK ' '

/* copies its input ot its output, replacing each string of one or more blanks by a single blank.*/
int main() {
	int c;
	int last = 'a';
	while ((c = getchar()) != EOF) {
		if (c != BLANK) {
			putchar(c);
		} else if (last != BLANK) {
			putchar(c);
		}		
		last = c;
	}
	return 0;
}
