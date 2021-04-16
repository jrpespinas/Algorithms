#include <stdio.h>

void encrypt(char* str, int* num);
void decrypt(char* str, int* num);
void printEncryption(int* str);
void printDecryption(char* str);

int main(){
    char str[1000];
    int num[1000];
    char str2[1000];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);
    encrypt(str, num);
    printEncryption(num);

    decrypt(str2, num);
    printDecryption(str2);
    return 0;
}

void encrypt(char* str, int* num){
    for(int i = 0; str[i] != '\0'; i++){
        num[i] = str[i] + 1; 
    }
}

void decrypt(char* str, int* num){
    for(int i = 0; num[i] != '\0'; i++){
        str[i] = num[i] - 1;
    }
}


void printEncryption(int* str){
    for(int i = 0; str[i] != '\0'; i++)
        printf("%d ", str[i]);
}

void printDecryption(char* str){
    printf("%s", str);
}
