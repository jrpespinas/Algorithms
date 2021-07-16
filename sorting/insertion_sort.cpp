#include <iostream>
using namespace std;

void insertion_sort(int arr[], int size) {
	for(int i=1; i<size; i++) {
		int j = i - 1;
		int key = arr[i];
		while (key < arr[j] && j >= 0) {
			arr[j + 1] = arr[j]; 
			j--;
		}
		arr[j + 1] = key;
	}
}


int main() {
	int arr[] = {3, 7, 12, 2, 13, 18, 24, 3, 8};	
	int size = sizeof(arr) / sizeof(int);
	insertion_sort(arr, size);
	for(int i=0; i<size; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
