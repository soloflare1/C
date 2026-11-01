#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char *word) {
    char keyword[][10] = {
        "int", "float", "char", "double", "if",
        "else", "while", "for", "return", "void",
        "scanf", "printf", "do", "break", "continue"
    };

    for (int i = 0; i < 15; i++) {
        if (strcmp(word, keyword[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {

    char code[1000];
    char token[100];

    int i = 0, j = 0;

    int k = 0, id = 0, n = 0, str = 0;
    int inc = 0, sp = 0;


    char *operators[] = {
        "++", "--",
        "+=", "-=", "*=", "/=", "%=",
        "==", "!=", "<=", ">=",
        "&&", "||",
        "+", "-", "*", "/", "%",
        "=", "<", ">", "!"
    };

    int opCount = 100;

    printf("code = \n");
    fgets(code, sizeof(code), stdin);

    printf("\nTokens:\n");

    while (code[i] != '\0') {

        if (isspace((unsigned char)code[i])) {
            i++;
            continue;
        }


        if (code[i] == '"') {
            printf("\"");
            i++;

            while (code[i] != '"' && code[i] != '\0') {
                putchar(code[i]);
                i++;
            }

            if (code[i] == '"') {
                printf("\" --> String \n");
                i++;
            }

            str++;
        }


        else if (isalpha((unsigned char)code[i]) || code[i] == '_') {

            j = 0;

            while (isalnum((unsigned char)code[i]) || code[i] == '_') {
                token[j++] = code[i++];
            }

            token[j] = '\0';

            if (isKeyword(token)) {
                printf("%s --> Keyword\n", token);
                k++;
            }
            else {
                printf("%s --> Identifier\n", token);
                id++;
            }
        }

        else if (isdigit((unsigned char)code[i])) {

            j = 0;

            while (isdigit((unsigned char)code[i]) || code[i] == '.') {
                token[j++] = code[i++];
            }

            token[j] = '\0';

            printf("%s --> Number\n", token);
            n++;
        }

        else {

            int found = 0;

            for (int x = 0; x < opCount; x++) {

                int len = strlen(operators[x]);

                if (strncmp(&code[i], operators[x], len) == 0) {

                    printf("%s --> ", operators[x]);

                    if (strcmp(operators[x], "++") == 0 ||
                        strcmp(operators[x], "--") == 0) {
                        printf("Increment/Decrement Operator\n");
                        inc++;
                    }

                    else if (strcmp(operators[x], "==") == 0 ||
                             strcmp(operators[x], "!=") == 0 ||
                             strcmp(operators[x], "<=") == 0 ||
                             strcmp(operators[x], ">=") == 0 ||
                             strcmp(operators[x], "<") == 0 ||
                             strcmp(operators[x], ">") == 0) {
                        inc++;
                    }

                    else if (strcmp(operators[x], "&&") == 0 ||
                             strcmp(operators[x], "||") == 0 ||
                             strcmp(operators[x], "!") == 0) {
                        inc++;
                    }

                    else if (strcmp(operators[x], "=") == 0 ||
                             strcmp(operators[x], "+=") == 0 ||
                             strcmp(operators[x], "-=") == 0 ||
                             strcmp(operators[x], "*=") == 0 ||
                             strcmp(operators[x], "/=") == 0 ||
                             strcmp(operators[x], "%=") == 0) {
                        inc++;
                    }

                    else {
                       inc++;
                    }

                    i += len;
                    found = 1;
                    break;
                }
            }

            if (!found) {

                printf("%c --> Special Symbol\n", code[i]);
                sp++;
                i++;
            }
        }
    }


    printf("Keyword = %d\n", k);
    printf("Identifier = %d\n", id);
    printf("Number = %d\n", n);
    printf("String                                                                                                                                     = %d\n", str);
    printf("Op = %d\n", inc);
    printf("Special Symbol = %d\n", sp);

    printf("Total Tokens = %d\n",inc);

    return 0;
}
