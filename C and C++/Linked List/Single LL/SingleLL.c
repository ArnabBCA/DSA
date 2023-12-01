#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} * first = NULL, * last = NULL;

// Displaying
void Display(struct Node* p) {
    if (p == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

// Inserting at the end to create a linked list
void InsertLast(int x) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL) {
        first = last = t;
    } else {
        last->next = t;
        last = t;
    }
}
//Count length
int Count(struct Node *p){  //Iterative     time=o(n), space=o(1) 
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}
//Deleting Node
int Delete(struct Node *p,int index){
    struct Node *q=NULL;
    int x= -1,i;

    if(index < 1 || index > Count(p)){  //for invalid index
        return -1;
    }
    if(index==1){             //for first node
        q=first;
        x=first->data;
        first=first->next;
        free(q);
        return x;          //return deleted element
    }
    else{
        for (i=0;i<index-1;i++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        free(p);
        return x;
    }
}

//Insering
void Insert(struct Node *p,int index,int x){
    struct Node *t;
    int i;

    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index<0|| index>Count(p)){  //if invalid Index
        return;
    }
    if(index==0){       //to insert before first node
        t->next=first;  //t is before first node so now t's next will point to first
        first=t;        //move first pointer to t node because it is no longer first node
    }
    else{               //to insert affter a given index
        for(i=0;i<index-1;i++){       //if indes is 4 then it shoud move index-1 times
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}


int main() {
    int choice, data, index;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert element at the end to create a linked list\n");
        printf("2. Display elements\n");
        printf("3. Delete a element\n");
        printf("4. Insert a element at any index\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to insert: ");
                scanf("%d", &data);
                InsertLast(data);
                break;
            case 2:
                printf("Elements in the linked list: ");
                Display(first);
                break;
            case 3:
                printf("Enter The index to Delete: ");
                scanf("%d", &index);
                printf("Deleted Element: %d", Delete(first, index));
                break;
            case 4:
                printf("Enter the index to insert the element: ");
                scanf("%d", &index);
                printf("Enter the element: ");
                scanf("%d", &data);
                Insert(first, index , data);
                break;

            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
