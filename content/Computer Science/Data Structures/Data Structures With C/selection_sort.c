#include <stdio.h>

void swap(int *xp, int *yp) {
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void selectionSort(int arr[], int n) {
	int i, j, minIndex, temp;
	
	for (i = 0; i < n-1; i++) {
		minIndex = i;
		for (j = i+1; j < n; j++) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		swap(&arr[minIndex], &arr[i]);
	}
}

int main() {
	int arr[] = {64, 25, 12, 22, 11};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	selectionSort(arr, n);
	
	printf("Sorted array: \n");
	for (int i=0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	
	return 0;
}

