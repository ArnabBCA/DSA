#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;


//Inserting at the end to create a ll
void Insert(int x){
    struct Node *t,*last;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

    if(first==NULL){
        first=last=t;
    }
    else{
        last->next=t;
        last=t;
    }
}

//Displaying
void Display(struct Node *p){ //Iterative
    if(p==NULL){
        printf("List is empty");
    }
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}

int main(){
    int size,i,value;
    printf("Enter the size ");
    scanf("%d",&size);
    for(i=0;i<size;i++){
        printf("Enter the value ");
        scanf("%d",&value);
        Insert(value);
    }
    Display(first);
    return 0;
}