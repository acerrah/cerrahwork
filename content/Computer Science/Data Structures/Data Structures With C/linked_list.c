#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

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

void display(node* head) {
    printf("Linked List: ");
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void free_list(node* head) {
    node* current = head;
    node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    node* head = NULL;

    insert(&head, 10);
    display(head);

    insert(&head, 20);
    display(head);

    insert(&head, 30);
    display(head);

    insert(&head, 40);
    display(head);
    
	insert(&head, 50);
    display(head);

	delete(&head, 30);
	display(head);

    free_list(head);

    return 0;
}


