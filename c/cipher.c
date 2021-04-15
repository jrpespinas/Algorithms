#include <stdio.h>

char* encrypt(char str[]);
char* decrypt(char str[]);

int main(){
    char str[1000];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);
    printf("%s\n", decrypt(encrypt(str)));
    return 0;
}

char* encrypt(char str[]){
    for(int i = 0; str[i] != '\0'; i++){
        str[i] += 1; 
    }
    return str;
}

char* decrypt(char str[]){
    for(int i = 0; str[i] != '\0'; i++){
        str[i] -= 1;
    }
    return str;
}
