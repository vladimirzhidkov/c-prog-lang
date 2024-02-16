#include <stdio.h>

#define TAB_WIDTH 4
#define TAB_STOPS 20

/* replaces strings of blanks by the minimum number of tabs and blanks to
 * achieve the same spacing.
*/
int main() {
	/* number of consecutive blanks */
	int nb;
	nb = 0;

	char c; /* current character */
	int i; /* position in line */
	i = 0;
	while ((c = getchar()) != EOF) {
		
		/* beyond the limit of tab stops */
		if (i/TAB_WIDTH >= TAB_STOPS) {
			putchar(c);
			if (c == '\n') 
				i = 0;	
		}	
	
		/* blank */	
		else if (c == ' ') {
			++nb;
			
			/* position at tabstop */
			if (i%TAB_WIDTH == TAB_WIDTH-1) {
				putchar('\t');
				nb = 0;
			}
			++i;
		}

		/* non blank */
		else { 
			int j;
			for (j = 0; j < nb; ++j) {
				putchar(' ');
			}
			nb = 0;
			putchar(c);
			
			++i;	
			if (c == '\n') {
				i = 0;
			}
		}
	}
	return 0;
}
