#include <stdio.h>

const char* capslock(char str[]);
const char* capitalize(char str[]);
int string_length(char str[]);

int main(){
    char str[1000];
    printf("please enter a string: ");
    scanf("%[^\n]s", str); 
    int length = string_length(str);
    printf("%s\n", capslock(str));
    printf("%s\n", capitalize(str));
}

const char* capslock(char str[]){
    // capitalize all letters of the string
    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= ('a' - 'A');
    }
    return str;
}

const char* capitalize(char str[]){
    for (int i = 0; str[i] != '\0'; i++){
        if (i == 0){
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] -= ('a' - 'A');
        }
        else if (str[i] == ' '){
            i++;
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] -= ('a' - 'A');
        }
        else {
            if (str[i] >= 'A' && str[i] <= 'Z')
                str[i] += ('a' - 'A');
        }
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
