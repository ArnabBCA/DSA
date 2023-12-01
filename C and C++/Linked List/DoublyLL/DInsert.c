#include <stdio.h>
#include <stdlib.h>

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=NULL;

void Create (int A[],int n){
    struct Node *t,*last;
    int i;

    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=first->next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;
    }
}

int Length(struct Node *p){
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}

void Display(struct Node *p){
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
}

void Insert(struct Node *p,int index,int x){
    struct Node *t;
    int i;
    if(index<0 || index>Length(p)){
        return;
    }
    if(index==0){ //inset before first node
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;
        t->prev=NULL;//because no node is present before
        t->next=first;
        first->prev=t;
        first=t;
    }
    else{ //insert at any other given index
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=x;

        t->prev=p;
        t->next=p->next;
        if(p->next){ //if next node is present
            p->next->prev=t;
        }
        p->next=t;
    }
}

int main(){
    int A[]={10,20,30,40,50};
    Create(A,5);
    Insert(first,0,25);
    Display(first);
    return 0;
}