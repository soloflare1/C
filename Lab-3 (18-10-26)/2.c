
#include <stdio.h>
#include <string.h>
#define MAX_SYMBOL 100

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

int addSymbol(Symbol table[], int count, char *name, char *type, char *kind, int scope, char *value) {
    if (count >= MAX_SYMBOL) {
        printf("Symbol table is full.\n");
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

void displayTable(Symbol table[], int count) {
    if (count == 0) {
        printf("\nSymbol table is empty.\n");
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

void searchSymbol(Symbol table[], int count, char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            printf("\nSymbol found successfully.\n");
            printf("Name: %s\n", table[i].name);
            printf("Type: %s\n", table[i].type);
            printf("Kind: %s\n", table[i].kind);
            printf("Scope: %d\n", table[i].scope);
            printf("Value: %s\n", table[i].value);
            return;
        }
    }

    printf("\nSymbol not found.\n");
}

int deleteSymbol(Symbol table[], int count, char *name) {
    for (int i = 0; i < count; i++) {
        if (strcmp(table[i].name, name) == 0) {
            for (int j = i; j < count - 1; j++) {
                table[j] = table[j + 1];
            }

            printf("\nSymbol deleted successfully.\n");
            return count - 1;
        }
    }

    printf("\nSymbol not found.\n");
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

    printf("Enter the number of symbols: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter symbol %d:\n", i + 1);

        printf("Name: ");
        scanf("%29s", name);

        printf("Type: ");
        scanf("%9s", type);

        printf("Kind: ");
        scanf("%9s", kind);

        printf("Scope: ");
        scanf("%d", &scope);

        printf("Value: ");
        scanf("%29s", value);

        count = addSymbol(
            table, count, name, type, kind, scope, value
        );
    }

    do {
        printf("\n===== Operations =====\n");
        printf("1. Display Symbol Table\n");
        printf("2. Search for a Symbol\n");
        printf("3. Delete a Symbol\n");
        printf("4. Exit Program\n");

        printf("Enter your choice: ");
        scanf("%d", &option);

        if (option == 1) {
            displayTable(table, count);
        }
        else if (option == 2) {
            printf("Enter the symbol name to search: ");
            scanf("%29s", name);

            searchSymbol(table, count, name);
        }
        else if (option == 3) {
            printf("Enter the symbol name to delete: ");
            scanf("%29s", name);

            count = deleteSymbol(table, count, name);
        }
        else if (option == 4) {
            printf("Exiting the program.\n");
        }
        else {
            printf("Invalid choice. Please try again.\n");
        }

    } while (option != 4);

    return 0;
}
