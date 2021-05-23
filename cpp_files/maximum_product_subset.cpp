#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 100000
#define MIN -100000

int input_set(int array[], int n);
int get_maximum_product(int array[], int n);

int main() {
    int n;
    cin >> n;

    if (n > MAX) {
        cout << "ERROR: Array size is too big!";
        return 0;
    }

    int array[n];

    if (input_set(array, n) == 0) {
        return 0;
    }

    cout << get_maximum_product(array, n);

    return 0;
}

int input_set(int array[], int n) {
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;

        if (num >= MAX or num <= MIN) {
            cout << "ERROR: input value exceeds range!";
            return 0;
        } else {
            array[i] = num;
        }
    }
    return 1;
}

int get_maximum_product(int array[], int n) {
    sort(array, array+n);
    return array[n-1] * array[n-2];
} 