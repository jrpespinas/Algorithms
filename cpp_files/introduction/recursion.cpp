#include <iostream>
#include <algorithm>
using namespace std;

string reverseSubstringLoop(string word, int start, int end);
void reverseSubstringRecursion(string &word, int start, int end, int i = 0);

int main(){
    string word;
    int start, end;
    cin >> word >> start >> end;
    reverseSubstringRecursion(word, start, end);
    cout << word;
    return 0;
}

string reverseSubstringLoop(string word, int start, int end){
    int length = word.length();
    
    for (int i = 0; i < length; i++) {
        if (i >= start - 1 && i <= end - 1) {
            swap(word[i], word[end]);
            end = end - 1;
        }
    }

    return word;
}

void reverseSubstringRecursion(string &word, int start, int end, int i) {
    int length = word.length();

    if (i == length){
        return;
    }
    else {
        if (i >= start - 1 && i <= end - 1) {
            swap(word[i], word[end]);
            reverseSubstringRecursion(word, start, end - 1, i + 1);
        }
        else {
            reverseSubstringRecursion(word, start, end, i + 1);
        }
    }
}