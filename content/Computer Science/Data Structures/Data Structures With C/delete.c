#include <stdio.h>

int main() {
	int capacity = 6;
	int size = 5;
	int array[6] = {1, 2, 3, 4, 5};
	
	// Print array before insertion
	printf("Array before insertion:\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	
	// Delete the last element
	int deleteIndex = size - 1;
	array[deleteIndex] = 0;
	size--;
	
	// Print array after insertion
	printf("Array after insertion:\n");
	for (int i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
	
	return 0;
}

