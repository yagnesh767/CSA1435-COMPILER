#include <stdio.h>
#include <ctype.h>
#include <string.h>

void lexicalAnalyzer(const char *input) {
    static int in_multiline_comment = 0;
    
    if (in_multiline_comment) {
        if (strstr(input, "*/")) {
            printf("Multi-line comment ended\n");
            in_multiline_comment = 0;
        }
        return;
    }
    
    if (strncmp(input, "//", 2) == 0) {
        printf("Single-line comment detected\n");
        return;
    }
    if (strncmp(input, "/*", 2) == 0) {
        printf("Multi-line comment detected\n");
        in_multiline_comment = 1;
        return;
    }
    
    while (*input) {
        if (isspace(*input)) { input++; continue; }
        if (isalpha(*input) || *input == '_') {
            printf("Identifier: %c\n", *input++);
            continue;
        }
        if (isdigit(*input)) {
            printf("Constant: %c\n", *input++);
            continue;
        }
        if (strchr("+-*/", *input)) {  // Recognizing only arithmetic operators
            printf("Arithmetic Operator: %c\n", *input++);
            continue;
        }
        input++;
    }
}

int main() {
    char input[200];
    printf("Enter input: \n");
    while (fgets(input, sizeof(input), stdin)) {
        lexicalAnalyzer(input);
    }
    return 0;
}
