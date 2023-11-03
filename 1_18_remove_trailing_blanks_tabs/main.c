#include <stdio.h>

#define MAX_LIMIT 100 
#define LIMIT 80

int get_line(char line[], int limit);
int remove_trailing_blanks_tabs(char line[], int length); 

// removes trailing blanks and tabs from each line of input, and deletes entirely blank line.
int main() {
	char line[MAX_LIMIT];
	int length;
	while ( (length = get_line(line, MAX_LIMIT)) && remove_trailing_blanks_tabs(line, length) ) {
		printf("%s", line);
	}
}

// length does not take into account \0, so line[length] = '\0'
// requirements: line ends with \n, so length > 0 
int remove_trailing_blanks_tabs(char line[], int length) {
	// ignore '\0' and '\n' at the end of line
	// so line[i] = element right before '\n'
	int i = length - 2;
	while (i >= 0 && (line[i] == ' ' || line[i] == '\t')) {
		--i;
	}
	// move '\n' and '\0' to new position
	line[++i] = '\n';
	line[i + 1] = '\0';	
	return i;
}
// size is line[] size 
// returns 0 if EOF is reached
// each line ends with "\n\0" and its length is at least 1 ('\n' counts)
int get_line(char line[], int size) {
	int c;
	int i;
	// reserve last 2 elements of line[] for '\n\0'
	for (i = 0; (c = getchar()) != EOF && c != '\n' && i < (size - 2); ++i) {
		line[i] = c;	
	}
	if (i == 0 && c == EOF || size < 2) {
		return 0;
	}
	line[i++] = '\n';	
	line[i] = '\0';
	// return line length does not account for '\0'. it's an indicator of the end of c-string
	return i;
}
