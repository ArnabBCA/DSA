#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
} *top = NULL;

void push(int x) {
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if (t == NULL) {
        printf("Stack is Full\n");
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop() {
    struct Node *t;
    int x = -1;
    if (top == NULL) {
        printf("Stack is Empty\n");
    } else {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

int peek(int index) {
    int i;
    struct Node *p;
    p = top;
    for (i = 0; p != NULL && i < index - 1; i++) {
        p = p->next;
    }
    if (p != NULL) {
        return p->data;
    } else {
        return -1;
    }
}

int stackTop() {
    if (top) {
        return top->data;
    } else {
        return -1;
    }
}

int isEmpty() {
    return top ? 0 : 1;
}

int isFull() {
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    int r = t ? 1 : 0;
    free(t);
    return r;
}

void display() {
    struct Node *p;
    p = top;
    if(p==NULL){
        printf("Stack is empty");
        return;
    }
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main() {
    int choice, x;

    while(1) {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Peek");
        printf("\n4. Stack Top");
        printf("\n5. Is Empty?");
        printf("\n6. Is Full?");
        printf("\n7. Display");
        printf("\n8. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                printf("Popped %d\n", pop());
                break;
            case 3:
                printf("Enter the index to peek: ");
                scanf("%d", &x);
                printf("Element at index %d is %d\n", x, peek(x));
                break;
            case 4:
                printf("Top element %d\n", stackTop());
                break;
            case 5:
                printf("Is Empty? %s\n", isEmpty() ? "Yes" : "No");
                break;
            case 6:
                printf("Is Full? %s\n", isFull() ? "Yes" : "No");
                break;
            case 7:
                display();
                break;
            case 8:
                printf("Exiting the program. Goodbye!\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    };

    return 0;
}
