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

int createTable(){
    return 0;
}

int addSymbol(
              Symbol table[],
              int count,
              char *name,
              char *type,
              char *kind,
              int scope,
              char *value
              )
{
                  for(int i = count; i > 0; i--){
                    table[i] = table[i - 1];
              }

              strcpy(table[0].name, name);
              strcpy(table[0].type, type);
              strcpy(table[0].kind, kind);
              table[0].scope = scope;
              strcpy(table[0].value, value);

              return count + 1;
}


void displayTable(Symbol table[], int count){
    printf("Name\tType\tKind\tScope\tValue\n");
    printf("--------------------------------------\n");

    for(int i = 0; i < count; i++){
        printf("%s\t%s\t%s\t%d\t%s\n",
           table[i].name,
           table[i].type,
           table[i].kind,
           table[i].scope,
           table[i].value
           );
    }
}

int main(){
    Symbol table[MAX_SYMBOL];
    int count = createTable();

    count = addSymbol(table, count, "x", "int", "var", 0, "10");
    count = addSymbol(table, count, "sum", "float", "func", 0, "");
    count = addSymbol(table, count, "y", "int", "var", 1, "5");

    displayTable(table, count);

    return 0;
}
