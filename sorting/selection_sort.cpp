#include <iostream>
using namespace std;

void selection_sort(int *arr, int size) {
    for (int i=0; i<size; i++) {
		int j=i;
		int minimum = j;
		while (j < size) {
			if (arr[j] < arr[minimum]) minimum = j;
			j++;
		}
		swap(arr[i], arr[minimum]);
	}
}

void display(int *arr, int size) {
	for(int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

	int arr[] = {3, 7, 12, 2, 13, 18, 24, 3, 8};	
	int size = sizeof(arr) / sizeof(int);
	selection_sort(arr, size);
	display(arr, size);
	return 0;
}
