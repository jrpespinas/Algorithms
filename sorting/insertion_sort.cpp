#include <iostream>
using namespace std;

void printArray(int A[], int len){
    for(int i = 0; i < len; i++){
        cout << A[i] << " ";
    }
}

void insertion_sort(int A[], int len){
    for(int i = 1; i < len; i++){
        int key = A[i];
        int j = i-1;
        while(key < A[j] && j >= 0){
            A[j + 1] = A[j];
            j -= 1;
        }
        A[j+1] = key;
    }
    printArray(A,len);
}

int main(){
    int len = 10;
    int A[] = {8,7,5,3,2,1,6,3,8,4};
    insertion_sort(A,len);
    return 0;
}
