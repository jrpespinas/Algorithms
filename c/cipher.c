#include <stdio.h>

const char* encrypt(char str[]);

int main(){
    char str[1000];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);
    printf("%s\n", encrypt(str));
    return 0;
}

const char* encrypt(char str[]){
    for(int i = 0; str[i] != '\0'; i++){
        str[i] += 1; 
    }
    return str; 
}
