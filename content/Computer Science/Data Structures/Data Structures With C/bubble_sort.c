#include <stdio.h>

void swap(int *xp, int *yp) { // swap function
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// bubble sort algorithm
void bubbleSort(int arr[], int n) { // n is the number of elements in the array
	for (int i = 0; i < n - 1; i++) { // i is the number of passes
		for (int j = 0; j < n - i - 1; j++) { // loop through the array from 0 to n - i - 1
			if (arr[j] > arr[j + 1]) { // if the current element is greater than the next element
			     swap(&arr[j], &arr[j + 1]); // swap the elements
			}
		}
	}
}

// main function to test the bubble sort algorithm
// int main() {
// 	int arr[] = {64, 34, 25, 12, 22, 11, 90};
// 	int n = sizeof(arr) / sizeof(arr[0]);

// 	bubbleSort(arr, n);

// 	printf("Sorted array: ");
// 	for (int i = 0; i < n; i++) {
// 		printf("%d ", arr[i]);
// 	}

// 	return 0;
// }
