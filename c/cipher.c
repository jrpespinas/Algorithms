#include <stdio.h>

char* encrypt(char* str, int* num);
void printEncryption(int* str);

int main(){
    char str[1000];
    int num[1000];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);
    encrypt(str, num);
    printEncryption(num);
    return 0;
}

char* encrypt(char* str, int* num){
    for(int i = 0; str[i] != '\0'; i++){
        num[i] = (int) str[i] + 1; 
    }
}


void printEncryption(int* str){
    for(int i = 0; str[i] != '\0'; i++)
        printf("%d ", str[i]);
}
