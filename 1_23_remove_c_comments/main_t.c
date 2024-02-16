#include <stdio.h>

int equal(char* s1, char* s2) {
	int i;
	for ( i = 0; s1[i] != '\0'; ++i ) {
		if ( s1[i] != s2[i] )
		return 0;
	}
	return 1;
}

/* removes all comments from c-program.
 * handles quoted strings and character constants properly. 
 */
int main() {
	char c;
	char to_print;
	int is_inside_comment;
	int is_inside_quotes;
	is_inside_comment = 0;
	is_inside_quotes = 0;

	char buffer[3]; 
	buffer[2] = '\0';

	/* populate buffer */
	buffer[0] = getchar();
	buffer[1] = getchar();
	
	if ( equal(buffer, "/*") )
		is_inside_comment = 1;

	/* start main loop of reading input */
	while ( (c = getchar()) != EOF ) {
		
		/* push input character through buffer */
		to_print = buffer[0];
		buffer[0] = buffer[1];
		buffer[1] = c;

		/* check for quotation mark ignoring \", '"' */
		if ( !is_inside_comment && buffer[1] == '"' &&
			buffer[0] != '\\' && buffer[0] != '\'' )
		{
			is_inside_quotes = !is_inside_quotes;
		}

		if (!is_inside_quotes) {
				
			/* comment begins */
			if ( !is_inside_comment && equal(buffer, "/*") ) {
				putchar(to_print);
				is_inside_comment = 1;
			}
			/* comment ends */
			else if ( is_inside_comment && equal(buffer, "*/") ) {
				is_inside_comment = 0;

				/* repopulate buffer and get rid of closing comment characters */
				buffer[0] = getchar();
				buffer[1] = getchar();

				if ( equal(buffer, "/*") ) {
					is_inside_comment = 1;
				}
			}
		}

		if ( !is_inside_comment ) {
			putchar(to_print);
		}
	}
	if ( !is_inside_comment ) {
		putchar(buffer[0]);
		putchar(buffer[1]);
	}
	return 0;
}
