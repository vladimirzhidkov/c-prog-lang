#include <stdio.h>

#define MAX_LIMIT 100 
#define LIMIT 80

int get_line(char line[], int limit);

/* prints all input lines that are longer than 80 characters.*/
int main() {
	char line[MAX_LIMIT];
	int length;
	while ((length = get_line(line, MAX_LIMIT))) {
		if (length > LIMIT) {
			printf("%s", line);
		}
	}
}

int get_line(char line[], int limit) {
	int c;
	int i;
	/* reserve 2 last elements of the limit for "\n\0" */
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
