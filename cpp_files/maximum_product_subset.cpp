#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000
#define MIN -100000

void input_set(int array[], int n);

int main() {
    int n;
    int array[MAX];
    cin >> n;

    input_set(array, n);

    return 0;
}

void input_set(int array[], int n) {
    for (int i = 0; i < n; i++) {
        cin >> array[i];
        if (array[i] >= MAX or array[i] <= MIN) {
            cout << "ERROR: input value exceeds range!";
            break;
        }
    }
}