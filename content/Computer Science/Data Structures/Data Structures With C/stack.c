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

void exitProgram() {
    printf("\n------ Program Finished ------\n");
}

int main() {
    int choice;

    do {
        printf("\nEnter your choice:\n");
        printf("1) Push\t2) Pop\t3) Display\t4) Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exitProgram();
                break;
            default:
                printf("\nChoose a number between 1-4");
        }
    } while (choice != 4);

    return 0;
}
