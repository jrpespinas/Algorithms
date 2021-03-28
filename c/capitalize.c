#include <stdio.h>

int main(){
    char str[1000];
    printf("please enter a string: ");
    scanf("%s", str);
   
    // find length of string 
    int length = 0;
    while (str[length] != '\0'){
        length++;
    }

    // capitalize all letters of the string
    for (int i = 0; i < length; i++){
        if (str[i] >= 'a' && str[i] <= 'z')
            printf("%c", str[i] - ('a' - 'A'));
        else
            printf("%c", str[i]);
    }
}
