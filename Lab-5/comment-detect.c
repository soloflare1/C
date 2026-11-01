#include <stdio.h>

int main() {
    char code[100];

    printf("Enter comment: ");
    fgets(code, 100, stdin);

    if (code[0] == '/' && code[1] == '/')
        printf("Single Line Comment");

    else if (code[0] == '/' && code[1] == '*')
        printf("Multi Line Comment");

    else
        printf("Not a Comment");

    return 0;
}
