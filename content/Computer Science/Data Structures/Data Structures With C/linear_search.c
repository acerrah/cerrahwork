#include <stdio.h>

int search(int arr[], int n, int item) {
	for(int i = 0; i < n; i++){
		if (arr[i] == item)
			return i; }
	return -1;
}

int main() {
	int size = 5;
	int array[] = {1, 2, 3, 4, 5};
	int to_search = 3;
	
	int result = search(array, size, to_search);

	if (result == -1)
		printf("element %d is not in the array \n", to_search);
	else
		printf("Element %d is at index %d \n", array[result], result);
	
	return 0;
}

