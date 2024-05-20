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

The above code defines a node structure for a linked list. The `data` field contains the value of the node, and the `next` field contains a pointer to the next node in the list.

```c

```
