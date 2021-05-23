#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000
#define MIN -100000

void input_set(int array[], int n);
int get_maximum_product(int array[], int n);

int main() {
    int n;
    cin >> n;

    if (n > MAX) {
        cout << "ERROR: Array size is too big!";
        return 0;
    }

    int array[n];

    input_set(array, n);
    cout << get_maximum_product(array, n);

    return 0;
}

void input_set(int array[], int n) {
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;

        if (num >= MAX or num <= MIN) {
            cout << "ERROR: input value exceeds range!";
            break;
        } else {
            array[i] = num;
        }
    }
}

int get_maximum_product(int array[], int n) {
    sort(array, array+n);
    return array[n-1] * array[n-2];
} 