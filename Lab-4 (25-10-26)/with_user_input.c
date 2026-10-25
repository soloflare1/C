#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char *word) {
    char keyword[][10] = {
        "int", "float", "if", "else", "while", "return"
    };

    for (int i = 0; i < 6; i++) {
        if (strcmp(word, keyword[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char code[200], token[50];
    int i = 0, j = 0;
    int k = 0, id = 0, n = 0, s = 0;

    printf("Enter code: ");
    scanf(" %[^\n]", code);

    while (code[i] != '\0') {
        if (isalnum(code[i]) ||(code[i] == '.' && j > 0 && isdigit(token[j - 1]))) {
            token[j++] = code[i];
        } else {
            if (j > 0) {
                token[j] = '\0';

                if (isKeyword(token)) {
                    printf("%s --> Keyword\n", token);
                    k++;
                } else if (isalpha(token[0])) {
                    printf("%s --> Identifier\n", token);
                    id++;
                } else {
                    printf("%s --> Number\n", token);
                    n++;
                }
                j = 0;
            }

            if (ispunct(code[i])) {
                printf("%c --> Special Symbol/Operator\n", code[i]);
                s++;
            }
        }
        i++;
    }

    if (j > 0) {
        token[j] = '\0';

        if (isKeyword(token)) {
            printf("%s --> Keyword\n", token);
            k++;
        } else if (isalpha(token[0])) {
            printf("%s --> Identifier\n", token);
            id++;
        } else {
            printf("%s --> Number\n", token);
            n++;
        }
    }

    printf("\nKeyword = %d\n", k);
    printf("Identifier = %d\n", id);
    printf("Number = %d\n", n);
    printf("Special Symbol/Operator = %d\n", s);
    printf("Total Tokens = %d\n", k + id + n + s);

    return 0;
}
