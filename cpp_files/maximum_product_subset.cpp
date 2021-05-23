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

    // Exits the program if the input size exceeds `MAX` or input size is less than 2
    if (n > MAX or n < 2) {
        cout << "ERROR: Array size is not acceptable!";
        return 0;
    }

    int array[n];

    // Exits the program if input value(s) exceed `MAX` and `MIN`
    if (input_set(array, n) == 0) {
        return 0;
    }

    // Return and output the maximum product from a pair of values in the array
    cout << get_maximum_product(array, n);

    return 0;
}

int input_set(int array[], int n) {
    int num;
    
    // Store input values into array
    for (int i = 0; i < n; i++) {
        cin >> num;

        // Returns 0 if input value exceeds `MAX` and `MIN`
        // otherwise store input to array[i]
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
    // Sort the array in ascending order
    sort(array, array+n);

    // Return the product of the last two indices `array`
    return array[n-1] * array[n-2];
} 