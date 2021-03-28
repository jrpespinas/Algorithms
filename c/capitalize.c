#include <stdio.h>

const char* capslock(char str[], int length);
int string_length(char str[]);

int main(){
    char str[1000];
    printf("please enter a string: ");
    scanf("%s", str); 
    int length = string_length(str);
    printf("%s", capslock(str, length));
}

const char* capslock(char str[], int length){
    // capitalize all letters of the string
    for (int i = 0; i < length; i++){
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= ('a' - 'A');
    }
    return str;
}

int string_length(char str[]){
    // find length of string 
    int length = 0;
    while (str[length] != '\0'){
        length++;
    }
    return length;
}
