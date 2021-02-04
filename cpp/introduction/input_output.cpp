#include <bits/stdc++.h>
using namespace std;


void InputSample1();
void InputSample2();
void InputSample3();

int main(){
    InputSample1();
    InputSample2();
    InputSample3();
    return 0;
}

void InputSample1(){
    // Ask the user for input using `cin`
    // Inputs are separated by new line.
    int a, b;
    string x;

    cout << "Input two integers and a string using `cin`: ";
    cin >> a >> b >> x;
}

void InputSample2(){
    // Ask the user for input using scanf
    // Faster but difficult implementation of cin
    int a, b;

    printf("%s", "Input two integers using `scanf`: ");
    if(scanf("%d %d", &a, &b) == 1) {};
}

void InputSample3(){
    // Ask the user for input using getline
    // This specific implementation accepts whitespaces as part of the input
    string x;

    cout << "Input a sentence using `getline`: "; 
    cin.ignore();
    getline(cin, x);
}
