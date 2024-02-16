#include <stdio.h>
#include <stdbool.h>

int main() {
    int c, nextC;
    bool inString = false;
    bool inChar = false;
    bool inComment = false;
    bool potentialCommentEnd = false;

    while ((c = getchar()) != EOF) {
        // Check for potential start of comment
        if (c == '/' && !inString && !inChar) {
            nextC = getchar();
            if (nextC == '*' && !inComment) {
                inComment = true;
                continue;
            } else if (nextC != EOF) {
                ungetc(nextC, stdin);
            }
        }

        // Check for potential end of comment
        if (c == '*' && !inString && !inChar) {
            nextC = getchar();
            if (nextC == '/' && inComment) {
                inComment = false;
                continue;
            } else if (nextC != EOF) {
                ungetc(nextC, stdin);
            }
        }

        // Track entering and exiting strings
        if (c == '\"' && !inChar && !inComment) {
            inString = !inString;
        }

        // Track entering and exiting character constants
        if (c == '\'' && !inString && !inComment) {
            inChar = !inChar;
        }

        // If not in comment, write the character
        if (!inComment) {
            putchar(c);
        }
    }

    return 0;
}

