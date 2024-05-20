#include <stdio.h>

int front = 0;
int rear = 0;
int queue[5];
int number = 0;

void insertion() {
    if (rear == 5)
        printf("\nQueue is Full");
    else {
        printf("\nEnter Number [%d]: ", number++);
        scanf("%d", &queue[rear++]);
    }
}

void deletion() {
    if (front == rear) {
        printf("\nQueue is empty");
    } else {
        printf("\nDeleted Element is %d", queue[front++]);
    }
}

void display() {
    printf("\nQueue elements: ");
    for (int i = front; i < rear; i++)
        printf("%d\t", queue[i]);
}

int main() {
    printf("\n----------- Insertion -----------------------\n");
    for (int i = 0; i < 6; i++)
        insertion();

    printf("\n----------- Show queue elements ------\n");
    display();

    printf("\n----------- Deletion ------------------------\n");
    deletion();

    printf("\n----------- Show queue elements ------\n");
    display();

    printf("\n----------- Show front & rear indexes--\n");
    printf("front refers to [%d] and rear refers to [%d]", front, rear);

    return 0;
}
