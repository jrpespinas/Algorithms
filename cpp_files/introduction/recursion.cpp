#include <iostream>
#include <algorithm>
using namespace std;

string reverseSubstringLoop(string word, int start, int end);

int main(){
    string word;
    int start, end;
    cin >> word >> start >> end;
    cout << reverseSubstringLoop(word, start, end);
    return 0;
}

string reverseSubstringLoop(string word, int start, int end){
    int length = word.length();
    
    for (int i = 0; i < length; i++) {
        if (i >= start && i <= end) {
            swap(word[i], word[end]);
            end = end - 1;
        }
    }

    return word;
}