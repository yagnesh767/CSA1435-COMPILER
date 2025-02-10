#include <stdio.h>
#include <ctype.h>
#include <string.h>

void lexicalAnalyzer(const char *input) {
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
        if (strchr("+-*/=<>!&|^", *input)) {
            printf("Operator: %c\n", *input++);
            continue;
        }
        input++;
    }
}

int main() {
    char input[100];
    printf("Enter input: ");
    fgets(input, sizeof(input), stdin);
    lexicalAnalyzer(input);
    return 0;
}
