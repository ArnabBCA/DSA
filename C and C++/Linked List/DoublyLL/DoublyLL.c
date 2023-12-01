#include <stdio.h>
#include <stdlib.h>

struct Node {
    struct Node* prev;  //Extra from Single ll
    int data;
    struct Node* next;
} * first = NULL, * last = NULL;

// Displaying 
void Display(struct Node* p) {       //same sa Single ll
    if (p == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int Length(struct Node *p){      //same as single ll
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}

// Inserting at the end to create a doubly linked list
void InsertLast(int x) { //almost same as single ll
    struct Node* t = (struct Node*)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    
    if (first == NULL) {
        t->prev = NULL;  // Set prev to NULL for the first element //only diff
        first = last = t;
    } else {
        t->prev = last;          //only diff
        last->next = t;
        last = t;
    }
}
//Insert
void Insert(struct Node *p,int index,int x){
    struct Node *t;
    int i;

    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index<0 || index>Length(p)){
        return;
    }
    if(index==0){ //inset before first node
        t->prev=NULL;//because no node is present before        //only diff
        t->next=first;  //because first is behind the new node t 
        first->prev=t;                 //only diff

        first=t; //bring ponter first in new node t       
    }
    else{ //insert at any other given index
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        t->prev=p; //because prev will be p which is back of t  //only diff
        t->next=p->next;  //because p-> next is font of t
        if(p->next){ //if next node is present  //only diff
            p->next->prev=t;
        }
        p->next=t;
    }
}

//delete

int Delete(struct Node *p,int index){
    int x=-1,i;
    if(index<1 || index > Length(p)){
        return -1;
    }
    if(index==1){ //delete first node
        first=first->next; 
        if(first){ //if first is not null
            first->prev=NULL;  //because no node is present behind
        }
        x=p->data;
        free(p);
        return x;
    }
    else{
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        p->prev->next=p->next;  //p is currently in the middle of prev and next
        if(p->next){    //if next node is present
            p->next->prev=p->prev;
        }
        x=p->data;
        free(p);
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
