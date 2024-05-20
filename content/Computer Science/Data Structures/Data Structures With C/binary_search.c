#include <stdio.h>

// binarySearch function to search target element in arr
// O(log n) time complexity
int binarySearch(int arr[], int left, int right, int target) {
	while (left <= right) { // Loop until all elements are checked
		int mid = left + (right - left) / 2; // Take mid element

		if (arr[mid] == target) // If target is found
			return mid; // Return index of target

		if (arr[mid] < target) // If target is greater than mid element
			left = mid + 1; // Update left index
		else // If target is smaller than mid element
			right = mid - 1; // Update right index
	}

	return -1;
}

// Main function to test binarySearch function

// int main() {
// 	int arr[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
// 	int n = sizeof(arr) / sizeof(arr[0]);
// 	int target = 18;
// 	int result = binarySearch(arr, 0, n - 1, target);

// 	if (result == -1)
// 		printf("Element not found\n");
// 	else
// 		printf("Element found at index %d\n", result);

// 	return 0;
// }
