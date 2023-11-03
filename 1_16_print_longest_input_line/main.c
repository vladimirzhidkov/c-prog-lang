#include <stdio.h>

#define MAX_LENGTH 100

int get_line(char line[], int limit);
void copy(char to[], char from[]);

// print the longest input line
int main() {
	char line[MAX_LENGTH];
	char longest[MAX_LENGTH];
	int len;
	int max = 0;

	while ( (len = get_line(line, MAX_LENGTH)) ) {
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
		
	printf("%s", longest);

	return 0;	
}

int get_line(char line[], int limit) {
	int c;
	int i;
	for (i = 0; (c = getchar()) != EOF && c != '\n' && i < (limit - 2); ++i) {
		line[i] = c;
	}
	if (i == 0 && c == EOF) {
		return 0;
	}
	line[i++] = '\n';
	line[i] = '\0';
	return i;
}

void copy(char to[], char from[]) {
	int c;
	int i;
	for (i = 0; (c = from[i]) != '\0'; ++i) {
		to[i] = from[i];	
	}
	to[i] = from[i];	
}
