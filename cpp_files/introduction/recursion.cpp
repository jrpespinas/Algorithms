#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

string reverseSubstringLoop(string word, int start, int end);
void reverseSubstringRecursion(string &word, int start, int end, int i = 0);
int checkConstraint(int length, int start, int end);

int main(){
    string word;
    int start, end;
    cin >> word >> start >> end;

    // reverseSubstringRecursion(word, start - 1, end - 1);
    // cout << word;

    cout << reverseSubstringLoop(word, start, end);

    return 0;
}

string reverseSubstringLoop(string word, int start, int end){
    int length = word.length();
    start -= 1;
    end -= 1;

    if (checkConstraint(length, start, end) == 0) {
        return "Exiting";
    }

    for (int i = 0; i < length; i++) {
        if (i >= start && i <= end) {
            swap(word[i], word[end]);
            end = end - 1;
        }
    }

    return word;
}

void reverseSubstringRecursion(string &word, int start, int end, int i) {
    int length = word.length();

    
    if (checkConstraint(length, start, end) == 0) {
        return;
    }

    if (i == length){
        return;
    }
    else {
        if (i >= start && i <= end ) {
            swap(word[i], word[end]);
            reverseSubstringRecursion(word, start, end - 1, i + 1);
        }
        else {
            reverseSubstringRecursion(word, start, end, i + 1);
        }
    }
}

int checkConstraint(int length, int start, int end) {
    if (length > 100 || length < 1){ 
        cout << "String exceeds specified length, ergo no changes!\n";
        return 0;
    }
    if (start >= end || start < 0) {
        cout << "Starting value falls outside of range!\n";
        return 0;
    }
    if (end <= start || end >= length) {
        cout << "Ending value falls outside of range!\n";
        return 0;
    }
    return 1;       
}