#include <stdio.h>

#define MAX 1000

void reverse(char s[]);
int get_line(char line[], int limit);

/*
reverses its input a line at a time.
*/
int main() {
	char line[MAX];
	while (get_line(line, MAX)) {
		reverse(line);
		printf("%s", line);
	}	
	return 0;
}
/*
reverses input string.
char s[] is a c-string.
*/
void reverse(char s[]) {

	/* find length */
	int end;
	for (end = 0; s[end] != '\0'; ++end) {
	}
	--end;

	/* reverse order in place */
	int start;
	int tmp;
	for (start = 0; start < end; ++start) {
		tmp = s[start];
		s[start] = s[end];
		s[end] = tmp;
		--end;
	}
}

/*
gets line from input
puts line in line[] as c-string
returns: length of line
*/
int get_line(char line[], int limit) {
	int c;
	int i;
	for (i = 0; (c = getchar()) != EOF && c != '\n' && i < (limit - 1); ++i) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i++] = c;
	}
	line[i] = '\0';
	return i;	
}
