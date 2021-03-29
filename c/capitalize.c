#include <stdio.h>

const char* capslock(char str[]);
const char* capitalize(char str[]);
const char* toLower(char str[]);
int string_length(char str[]);
int isLower(char letter);
int isUpper(char letter);

int main(){
    char str[1000];
    printf("please enter a string: ");
    scanf("%[^\n]s", str); 
    printf("%s\n", capitalize(str));
    printf("%s\n", capslock(str));
    printf("%s\n", toLower(str));
    }

const char* capslock(char str[]){
    // capitalize all letters of the string
    for (int i = 0; str[i] != '\0'; i++){
        if (isLower(str[i]))
            str[i] -= ('a' - 'A');
    }
    return str;
}

const char* capitalize(char str[]){
    // capitalize the first letter per word
    for (int i = 0; str[i] != '\0'; i++){
        if (i == 0){
            if (isLower(str[i]))
                str[i] -= ('a' - 'A');
        }
        else if (str[i] == ' '){
            i++;
            if (isLower(str[i]))
                str[i] -= ('a' - 'A');
        }
        else {
            if (isUpper(str[i]))
                str[i] += ('a' - 'A');
        }
    }
    return str;
}

const char* toLower(char str[]){
    int i = 0;
    while (str[i] != '\0'){
        if (isUpper(str[i]))
            str[i] += ('a' - 'A');
        i++;
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


int isLower(char letter){
    return (letter >= 'a' && letter <= 'z');
}

int isUpper(char letter){
    return (letter >= 'A' && letter <= 'Z');
}
