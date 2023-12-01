#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
} * first;

// Displaying C_LL
void Display(struct Node* h) {
    if (h == NULL) {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = h;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != h);
    printf("\n");
}

// Inserting at the end to create a linked list
void InsertLast(int x) {
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (first == NULL) {
        first = t;
        first->next = first; // Set the next pointer to itself for a circular linked list
    } else {
        struct Node* last = first;
        while (last->next != first) {
            last = last->next;
        }
        last->next = t;
        t->next = first;
    }
}
//Find length of C_LL
int Length(struct Node *p){
    int len=0;
    do{
        len++;
        p=p->next;
    }while(p!=first);
    return len;
}
// Insert
void Insert(struct Node *p,int index,int x){
    struct Node *t;
    int i;
    if(index<0 || index>Length(first)){
        return;
    }
    if(index==0){  //to insert before head node
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        if(first==NULL){  
            first=t;
            first->next=first;  //make it point on itself because it is the only node
        }
        else{   
            while(p->next!=first){
                p=p->next;
            }
            p->next=t;
            t->next=first;
            first=t;
        }
    }
    else{       //same as single LL
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->next=p->next;
        p->next=t;
    }
}

int Delete(struct Node *p,int index){
    struct Node *q;
    int i,x;
    if(index<1 || index>Length(first)){
        return -1;                            //invalid index
    }
    if(index==1){                            //deleting head node
        while(p->next!=first){           //to move to the last node
            p=p->next;
        }
        x=first->data;           //to copy data and store
        if(first==p){   //if it the only node or last node
            free(first);
            first=NULL;
        }
        else{  //it it is not last node
            p->next=first->next;
            free(first);
            first=p->next;
        }
    }
    else{          //delete any node. similar to linear linked list
        for(i=0;i<index-1;i++){  //because node starts from 1
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
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
