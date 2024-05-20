#include <stdio.h>

int main() {
	int size = 5;
	int array[] = {1, 2, 3, 4, 5};
	
	// Print array before insertion
	int to_search = 3;
	for (int i = 0; i < size; i++) {
		if (to_search == array[i])
		{
			printf("Element %d is at index %d \n", array[i], i);
			return 0;
		}
	}
	printf("element %d is not in the array \n", to_search);
	return 0;
}

