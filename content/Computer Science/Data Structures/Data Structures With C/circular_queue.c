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

// // main function to test the circular queue
// int main() {
//     printf("------------- Insertion -----------------------------\n");
//     for (int i = 0; i < 6; i++)
//         insertion();

//     printf("\n----------- Display queue elements -------------------\n");
//     display();

//     printf("\n----------- Deletion --------------------------------");
//     deletion();
//     deletion();

//     printf("\n----------- Display queue elements -----------------\n");
//     display();

//     printf("\n----------- Show front & rear indexes---------------\n");
//     printf("Front refers to index [%d], Rear refers to index [%d]", front % Max, rear % Max);

//     printf("\n----------- Number of free space in Queue-----------");
//     printf("\nNumber of free space in Queue is %d", Max - count);

//     printf("\n------------- Insertion ----------------------------\n");
//     insertion();

//     printf("\n----------- Display queue elements -----------------\n");
//     display();

//     return 0;
// }
