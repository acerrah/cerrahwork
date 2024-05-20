#include <stdio.h>
#include <stdlib.h>

// hash is a data structure that stores key-value pairs
// hash function is used to generate an index for a key
// hash collision is when two keys have the same index
// chaining is a technique to handle hash collisions
// hash table is an array of linked lists
#define SIZE 10

typedef struct Node {
	int key;
	int value;
	struct Node* next;
} Node;

Node* hashTable[SIZE];

int hashFunction(int key) {
	return key % SIZE;
}

void insert(int key, int value) {
	int index = hashFunction(key);
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->key = key;
	newNode->value = value;
	newNode->next = NULL;

	if (hashTable[index] == NULL) {
		hashTable[index] = newNode;
	} else {
		Node* current = hashTable[index];
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = newNode;
	}
}

int search(int key) {
	int index = hashFunction(key);
	Node* current = hashTable[index];
	while (current != NULL) {
		if (current->key == key) {
			return current->value;
		}
		current = current->next;
	}
	return -1;
}

void display() {
	for (int i = 0; i < SIZE; i++) {
		printf("Index %d: ", i);
		Node* current = hashTable[i];
		while (current != NULL) {
			printf("(%d, %d) ", current->key, current->value);
			current = current->next;
		}
		printf("\n");
	}
}

// int main() {
// 	for (int i = 0; i < SIZE; i++) {
// 		hashTable[i] = NULL;
// 	}

// 	insert(1, 10);
// 	insert(2, 20);
// 	insert(3, 30);
// 	insert(4, 40);
// 	insert(5, 50);

// 	display();

// 	int key = 3;
// 	int value = search(key);
// 	if (value != -1) {
// 		printf("Value for key %d: %d\n", key, value);
// 	} else {
// 		printf("Key %d not found\n", key);
// 	}

// 	return 0;
// }
