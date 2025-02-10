#include <stdio.h>
#include <string.h>

// Function to check if a line is a comment
int is_comment(const char *line) {
    // Skip leading whitespace
    while (*line == ' ' || *line == '\t') line++;
    // Check for single-line or multi-line comments
    return strncmp(line, "//", 2) == 0 || strncmp(line, "/*", 2) == 0 || strstr(line, "*/") != NULL;
}

int main() {
    // Sample inputs
    const char *inputs[] = {
        "// This is a single-line comment",
        "/* This is a multi-line comment */",
        "int x = 10; // This is code with a comment",
        "/* This is the start of a multi-line comment",
        "This is the end of a multi-line comment */",
        "This is not a comment"
    };

    int num_inputs = sizeof(inputs) / sizeof(inputs[0]);

    // Check each input and print the result
    for (int i = 0; i < num_inputs; i++) {
        if (is_comment(inputs[i])) {
            printf("'%s' is a comment.\n", inputs[i]);
        } else {
            printf("'%s' is not a comment.\n", inputs[i]);
        }
    }

    return 0;
}