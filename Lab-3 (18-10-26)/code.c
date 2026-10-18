#include <stdio.h>
#include <string.h>
#define MAX_SYMBOL 5

typedef struct Symbol {
    char name[30];
    char type[10];
    char kind[10];
    int scope;
    char value[30];
} Symbol;

int createTable() {
    return 0;
}

int addSymbol(Symbol table[],
              int count,
              char *name,
              char *type,
              char *kind,
              int scope,
              char *value) {
    if (count >= MAX_SYMBOL)
    {
        printf("full!\n");
        return count;
    }

    for (int i = count; i > 0; i--) {
        table[i] = table[i - 1];
    }


    strcpy(table[0].name, name);
    strcpy(table[0].type, type);
    strcpy(table[0].kind, kind);
    table[0].scope = scope;
    strcpy(table[0].value, value);

    return count + 1;
}

void displayTable(Symbol table[], int count)
{
    if (count == 0) {
        printf("\nempty!\n");
        return;
    }

    printf("\nName\tType\tKind\tScope\tValue\n");
    printf("--------------------------------------\n");

    for (int i = 0; i < count; i++) {
        printf("%s\t%s\t%s\t%d\t%s\n",
               table[i].name,
               table[i].type,
               table[i].kind,
               table[i].scope,
               table[i].value);
    }
}


void searchSymbol(Symbol table[],
                  int count,
                  char *name
                  ) {
    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            printf("\nSymbol Found!\n");
            printf("name: %s\n", table[i].name);
            printf("type: %s\n", table[i].type);
            printf("kind: %s\n", table[i].kind);
            printf("scope: %d\n", table[i].scope);
            printf("value: %s\n", table[i].value);
            return;
        }
    }

    printf("\nnot found!\n");
}

int deleteSymbol(Symbol table[], int count, char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {

            for (int j = i; j < count - 1; j++) {
                table[j] = table[j + 1];
            }

            printf("\ndeleted!\n");
            return count - 1;
        }
    }

    printf("\nnot found!\n");
    return count;
}

int main() {

    Symbol table[MAX_SYMBOL];
    int count = createTable();
    int n, option;

    char name[30];
    char type[10];
    char kind[10];
    int scope;
    char value[30];

    printf("Enter no of symbols: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter symbol %d:\n", i + 1);
        printf("name: ");
        scanf("%29s", name);
        printf("type: ");
        scanf("%9s", type);
        printf("kind: ");
        scanf("%9s", kind);
        printf("scope: ");
        scanf("%d", &scope);
        printf("value: ");
        scanf("%29s", value);

        count = addSymbol(
            table, count, name, type, kind, scope, value
        );
    }


    do {
        printf("\n         Output           \n");
        printf("----------------------------\n");
        printf("1. Display Symbols\n");
        printf("2. Search Symbol\n");
        printf("3. Delete Symbol\n");
        printf("4. Exit\n");

        printf("Enter option: ");
        scanf("%d", &option);

        if (option == 1) {
            displayTable(table, count);
        }
        else if (option == 2) {
            printf("Enter name to search: ");
            scanf("%29s", name);

            searchSymbol(table, count, name);
        }
        else if (option == 3) {
            printf("Enter name to delete: ");
            scanf("%29s", name);

            count = deleteSymbol(table, count, name);
        }
        else if (option == 4) {
            printf("Exit\n");
        }
        else {
            printf("Invalid\n");
        }

    } while (option != 4);

    return 0;
}
