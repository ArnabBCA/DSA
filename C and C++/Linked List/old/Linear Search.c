#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void create(int A[],int n){
    int i;
    struct Node *t,*last;
    first =(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];
    first->next=NULL;
    last=first;

    for (i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

struct Node*LSearch(struct Node *p,int key){          //iterative
    while(p){
        if(key==p->data){
            return p;
        }
        else{
            p=p->next;
        }
    }
    return 0;
}
struct Node*RSearch(struct Node *p,int key){        //recursive
    if(p==NULL){
        return NULL;
    }
    if(key==p->data){
        return p;
    }
    return RSearch(p->next,key);
}

int main(){
    struct Node *temp;
    int A[]={3,5,7,10,15};
    create(A,5);
    //temp =LSearch(first,7);
    temp =RSearch(first,7);
    if(temp){
        printf("Key is found %d",temp->data);
    }
    else{
        printf("Key is not found %d");
    }
    return 0;
}