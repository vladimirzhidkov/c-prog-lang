#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_N_COLUMNS 80
#define WORD_LENGTH_LIMIT 40

int getword(char word[], int limit);

/* "folds" gracefully long input lines into two or more shorter lines after the
 * last non-blank character that occurs before the n-th column of input.
 */
int main(int argc, char* argv[]) {
	int ncolumns = DEFAULT_N_COLUMNS;
	if (argc > 1 && (ncolumns = atoi(argv[1])) < 1) {
		ncolumns = DEFAULT_N_COLUMNS;
	}	
	char word[WORD_LENGTH_LIMIT];
	int line_length = 0;
	int i;
	i = 0;
	while ((i = getword(word, WORD_LENGTH_LIMIT))) {
		if (line_length+i > ncolumns) {
			putchar('\n');
			line_length = 0;
		}
		printf("%s", word);	
		line_length += i;
		if (word[i-1] == '\n') 
			line_length = 0;
	}
	return 0;
}

/* gets word delimited by ' ' or '\n' and stores it in word[]
 * word is c-string that includes the above delimiter.
 * returns word length including delimiter.
 */
int getword(char word[], int limit) {
	int i;
	char c;
	for (i = 0; (c = getchar()) != EOF && i < limit-2
		&& c != ' ' && c != '\n'; ++i)
	{
		word[i] = c;
	}
	if (c != EOF) {
		word[i++] = c;
	}
	word[i] = '\0';
	return i;
}
