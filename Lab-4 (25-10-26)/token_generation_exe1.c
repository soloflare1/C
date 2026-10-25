#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char *word){
    char keyword[][10] = {
        "int", "float", "if", "else", "while", "return"
    };
    for(int i = 0; i < 6; i++){
        if(strcmp(word, keyword[i]) == 0)
            return 1;
    }
    return 0;
}

int main(){

  char code[] = "int x = 10; float y = x + 20;";
  char token[50];
  int i = 0, j = 0;

  printf("Token:\n");

  while(code[i] != '\0'){
    if(isalnum(code[i])){
        token[j++] = code[i];
    }
    else{
        if(j != 0){
            token[j] = '\0';
            if(isKeyword(token))
                printf("%s --> Keyword\n", token);
            else if(isalpha(token[0]))
                printf("%s --> Identifier\n", token);
            else
                printf("%s --> Number\n", token);
            j = 0;
        }
        if(ispunct(code[i]) && code[i] != ' '){
            printf("%c --> Special Symbol/Operator\n", code[i]);
        }
    }
    i++;
  }
  return 0;
}
