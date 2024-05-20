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
// main function to test the code
// int main() {
//     root('A');
//     left_set('B', 0);
//     right_set('C', 0);
//     left_set('D', 1);
//     right_set('E', 1);
//     right_set('F', 2);
//     left_set('G', 3);
//     right_set('H', 3);
//     print_tree();
//     return 0;
// }
