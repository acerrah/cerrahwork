# Data Structures

Data structures are a way of organizing and storing data efficiently. There are many types of data structures, each with its own advantages and disadvantages. In this chapter, we will discuss some of the most common data structures and their uses.

## Arrays

An array is a collection of elements that are stored in contiguous memory locations. Each element in an array is accessed by its index. Arrays are used to store a fixed-size collection of elements of the same type.

```c
int arr[5] = {1, 2, 3, 4, 5};
```

The above code creates an array of integers with 5 elements. The elements of the array can be accessed using the index of the element.

```c
int *arr = malloc(5 * sizeof(int));
```

The above code creates an array of integers with 5 elements using dynamic memory allocation. For more information on dynamic memory allocation, see the guide on [[memory management on C]].

## Linked Lists

A linked list is a collection of elements that are stored in non-contiguous memory locations. Each element in a linked list is called a node and contains a value and a pointer to the next node in the list. Linked lists are used to store a variable-size collection of elements.

```c
struct Node {
    int data;
    struct Node *next;
};
```

The above code defines a node structure for a linked list. The `data` field contains the value of the node, and the `next` field contains a pointer to the next node in the list. Here is an example of a linked list impementation with some basic operations such as insertion, deletion, and display.

```c
#include <stdio.h>
#include <stdlib.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Function to create a new node
node* createnode(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}
// Function to insert a new node at the end of the list
void insert(node** head, int data) {
    node* new_node = createnode(data);
    if (*head == NULL) {
        *head = new_node;
    } else {
        node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}
// Function to delete a node from the list
void delete(node** head, int data) {
	node* current = *head;
	node* previous = NULL;
	while (current != NULL) {
		if (current->data == data) {
			if (previous == NULL) {
				*head = current->next;
			} else {
				previous->next = current->next;
			}
			free(current);
			return;
		}
		previous = current;
		current = current->next;
	}
}
// Function to display the list
void display(node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
// Function to free the list
void free_list(node* head) {
    node* current = head;
    node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}
```

The above code defines a linked list structure and some basic operations on it. The `createnode` function creates a new node with the given data. The `insert` function inserts a new node at the end of the list. The `delete` function deletes a node with the given data from the list. The `display` function displays the list. The `free_list` function frees the memory allocated for the list.

## Stacks

A stack is a collection of elements that are stored in a last-in, first-out (LIFO) order. Elements can be added to or removed from the top of the stack. We can give example from real life as a stack of plates. The last plate that is placed on the stack is the first one to be removed. But how do we implement a stack in C?

```c
#include <stdio.h>

int top = 0;
int stack[5];

int push() {
    int a;

    if (top > 4)
        printf("Stack is Overflow");
    else {
        printf("\nEnter number: ");
        scanf("%d", &a);
        stack[top] = a;
        printf("\nNumber [%d] pushed into stack", stack[top]);
        top++; // Note: top refers to the next empty space
    }
}

void pop() {
    if (top == 0)
        printf("Stack is Empty");
    else {
        top--; // Note: top refers to the next full space
        printf("\nElement [%d] removed from stack", stack[top]);
    }
}

void display() {
    printf("\nElements in the stack:");
    for (int i = 0; i < top; i++)
        printf("\t%d", stack[i]);
}
```

The above code uses an array to implement a stack. The `push` function adds an element to the top of the stack. The `pop` function removes an element from the top of the stack. The `display` function displays the elements in the stack. The `top` variable keeps track of the top of the stack.

In this example the stack is implemented as a global variable. In practice, it is better to encapsulate the stack in a structure and provide functions to manipulate it. This will make the code more modular and easier to maintain. But for simplicity, we have used a global variable in this example.

Also note that the stack has a fixed size of 5 elements. In practice, you may want to use dynamic memory allocation to create a stack of variable size or use a linked list to implement a stack which will be slower to access to a target but easier to manipulate . Keep in mind that the stack is a simple data structure and can be implemented in many different ways.

## Queues

A queue is a collection of elements that are stored in a first-in, first-out (FIFO) order. Elements can be added to the back of the queue and removed from the front of the queue. We can give example from real life as a queue of people waiting in line. The first person to arrive is the first one to be served. But how do we implement a queue in C?

```c
#include <stdio.h>

struct node {
    int data;
    struct node *next;
};

node *front = NULL;
node *rear = NULL;

void enqueue(int data) {
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;

    if (front == NULL) {
        front = new_node;
        rear = new_node;
    } else {
        rear->next = new_node;
        rear = new_node;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Queue is Empty");
    } else {
        node *temp = front;
        front = front->next;
        free(temp);
    }
}
```

The above code uses a linked list to implement a queue. The `enqueue` function adds an element to the back of the queue. The `dequeue` function removes an element from the front of the queue. The `front` and `rear` pointers keep track of the front and back of the queue.

The reason we used linked list instead of an array is that the array is not effiecent for this kind of operation. Because when we remove an element from the front of the queue, we need to shift all the other elements to the left. This operation has a time complexity of O(n), where n is the number of elements in the queue. But with linked list, we can remove the element from the front of the queue in O(1) time.

In some cases we can use circular queue to avoid the shifting operation so we can use the array to implement the queue which will be faster and uses less memory space. We will discuss circular queue in the next section.

## Circular Queues

A circular queue is a variation of a queue in which the last element is connected to the first element. This allows us to reuse the space in the queue when it becomes full. Here is an example of how to implement a circular queue in C:

```c
#include <stdio.h>

// circular queue implementation using array
int front = 0;
int rear = 0;
int Max = 5;
int queue[10];
int count = 0;

// function to insert element in queue
void insertion() {
    if (count == Max) // check if queue is full
        printf("\nQueue is Full");
    else { // insert element in queue
        printf("\nEnter Number [%d]: ", count++);
        scanf("%d", &queue[rear++]);
        rear = rear % Max; // rear is set to 0 if it reaches Max
    }
}

// function to delete element from queue
void deletion() {
    if (count == 0) { // check if queue is empty
        printf("\nQueue is empty\n");
    } else { // delete element from queue
        printf("\nDeleted Element is %d", queue[front]);
        front = (front + 1) % Max; // adding 1 to front to unsee the deleted element
        count--;
    }
}

// function to display elements of queue
void display() {
    int j;
    if (count == 0) {
        printf("Queue is empty");
    } else {
        j = count;
        for (int i = front; j != 0; j--) {
            printf("%d \t", queue[i]);
            i = (i + 1) % Max;
        }
    }
}

```

The above code uses an array to implement a circular queue. The `insertion` function adds an element to the back of the queue. The `deletion` function removes an element from the front of the queue. The `display` function displays the elements in the queue. The `front` and `rear` pointers keep track of the front and back of the queue.

The `front` and `rear` pointers are incremented by 1 after each insertion and deletion operation. The `%` operator is used to wrap around the pointers when they reach the end of the array. This allows us to reuse the space in the queue when it becomes full.

Circular queues are used in situations where we need to process a stream of data with a small buffer. For example, in networking applications, circular queues are used to store incoming packets before they are processed. To not lose any data, we can use circular queue to store the data and process it while the new data is coming. When some of the data is processed, we can remove it from the queue and add the new data to the queue and so on.

## Priority Queues

A priority queue is a data structure that stores elements in a queue and assigns a priority to each element. The element with the highest priority is removed first. Priority queues are commonly used in operating systems to schedule tasks based on their priority.

## Trees

A tree is a hierarchical data structure that consists of nodes connected by edges. Each node has a value and zero or more child nodes. The top node of the tree is called the root node. The nodes at the bottom of the tree are called leaf nodes. Trees are used to represent hierarchical relationships between data.

There are many types of trees, such as binary trees, binary search trees, AVL trees, red-black trees, and B-trees. Each type of tree has its own properties and uses. But in this guide, we will focus on binary trees, for more details I might write a separate guide for each type of trees.

## Binary Trees

A binary tree is a tree in which each node has at most two child nodes, referred to as the left child and the right child. The left childs value is less than the parent node and the right childs value is greater than the parent node. Binary trees are designed to allow for efficient searching, insertion, and deletion of elements. Here is an example of how to implement a binary tree in C:

```c
#include <stdio.h>

// tree implemented as an array
char tree[10];

// create a root node
int root(char key) {
    if (tree[0] != '\0')
        printf("Tree already has a root");
    else
        tree[0] = key;
    return 0;
}

// set left child
int left_set(char key, int parent) {
    if (tree[parent] == '\0') { // parent not found
        printf("\nCan't set child at [%c], no parent found", (parent * 2) + 1);
        return 1;
    }
    else // parent found
        tree[(parent * 2) + 1] = key; // set left child
    return 0;
}

int right_set(char key, int parent) {
    if (tree[parent] == '\0') { // parent not found
        printf("\nCan't set child at [%c], no parent found", (parent * 2) + 2);
        return 1;
    }
    else // parent found
        tree[(parent * 2) + 2] = key; // set right child
    return 0;
}

int print_tree() { // print the tree
    printf("\n---------------- Output ----------\n");
    for (int i = 0; i < 10; i++) {
        if (tree[i] != '\0')
            printf("%c", tree[i]);
        else
            printf("-");
    }
    return 0;
}
```

The above code uses an array to implement a binary tree. The `root` function creates a root node with the given key. The `left_set` and `right_set` functions set the left and right child nodes of a given parent node. The `print_tree` function prints the elements of the tree.

The code is simple and easy to understand. It uses an array to store the elements of the tree. The root node is stored at index 0, and the left and right child nodes are stored at indices `(parent * 2) + 1` and `(parent * 2) + 2`, respectively.

Using array to implement the binary tree is not really necessary for most of the cases, but it is a good way to understand how the binary tree works. In most cases, we use pointers to implement the binary tree.

Using this binary tree, we can search using the binary search algorithm, insert elements, delete elements, and traverse the tree in different ways. We can also use the binary tree to implement other types of trees, such as binary search trees, AVL trees, and red-black trees.

## Hash Tables

A hash table is a data structure that stores key-value pairs. It uses a hash function to map keys to values.Hash functiosn are used to convert the key into an index in the hash table. The hash function should be fast and should distribute the keys as uniformly as possible across the hash table. The hash function is not reversible, so it is not possible to retrieve the key from the value. Only the value can be retrieved using the key with the help of the hash function. Here is an example of how to implement a hash table in C:

```c
#include <stdio.h>
#include <stdlib.h>

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
```

The above code uses an array of linked lists to implement a hash table. The `hashFunction` function calculates the index of the hash table for a given key. The `insert` function inserts a key-value pair into the hash table. The `search` function searches for a value in the hash table using the key.

You might have noticed that the hash table is implemented using an array of linked lists. This is because collisions can occur when two keys map to the same index in the hash table. When a collision occurs, the key-value pair is added to the linked list at that index. This allows us to handle collisions and store multiple key-value pairs at the same index.

Hash tables are commonly used in computer science and programming because they provide fast access to data. They have an average time complexity of O(1) for insertion, deletion, and search operations. However, the worst-case time complexity can be O(n) if all keys map to the same index in the hash table. To avoid this, a good hash function should be chosen that distributes the keys uniformly across the hash table.

## Can you crack a hash table?

You can't reverse a hash function, but you can try to crack a hash table by using a technique called hash collision. A hash collision occurs when two different keys map to the same index in the hash table. This can be exploited to crack a hash table by inserting a key-value pair that collides with the target key-value pair. When the target key is searched for, the colliding key is returned instead. But this doesn't mean that you have cracked the hash table, as you are not able to retrieve the original key from the colliding key. You can only retrieve the value associated with the colliding key. I stress again that hash functions are not reversible, so you can't retrieve the original key from the value. Many people knows this wrong concept. **HASHING IS NOT CRYPTOGRAPHY.** We do math, not magic.

## Conclusion

There are many other data structures that have different usages and specific cases where they are more efficient than others. The data structures mentioned in this article are some of the most commonly used data structures in computer science and programming. Understanding how these data structures work and when to use them is essential for writing efficient and optimized code. I hope this guide has helped you understand the basics of data structures and their implementations in C. If you have any questions or feedback, feel free to contect me thourgh my email. I will be happy to help you. Thank you for reading.
