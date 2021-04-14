#include <stdio.h>

int relu(int num);
int relu_two(int num);

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("%i\n", relu(num));
    printf("%i\n", relu_two(num));
    return 0;
}

int relu(int num){
    if (num >= 0) 
        return num;
    else
        return 0;
}

int relu_two(int num){
    return (num >= 0 ? num : 0);
}
