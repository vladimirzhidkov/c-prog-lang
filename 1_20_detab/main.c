#include <stdio.h>

#define TAB_WIDTH 4
#define TAB_STOPS 20 
/*
replaces tabs in the input with the proper number of blanks
to space to the next tab stop.
Assume a fixed set of tab stops, say every n columns.
*/
int main() {
	char c;
	int i;
	i = 0;
	while ((c = getchar()) != EOF) {

		/* tab */
		if ((i / TAB_WIDTH) < TAB_STOPS && c == '\t') {

			/* calculate N of blanks */
			int nb;
			nb = TAB_WIDTH - i % TAB_WIDTH;

			/* insert blanks */
			int j;
			for (j = 0; j < nb; ++j) {
				putchar(' ');
			}
			i += nb;

		} else {
			putchar(c);
			++i;
		}
		
		/* new line */
		if (c == '\n') {
			i = 0;
		}		
	}		
	return 0;
}
