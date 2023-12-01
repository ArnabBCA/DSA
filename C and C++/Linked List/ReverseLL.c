#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;


void Create(int A[],int n){
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));
    first -> data=A[0];
    first -> next=NULL;
    last=first;

    for(i=1;i<n;i++){
        t=(struct Node*)malloc(sizeof(struct Node));
        t ->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
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

//revesing using array
void Reverse1(struct Node *p){
    int *A,i=0;
    struct Node *q=p;
    A=(int *)malloc(sizeof(int)*Count(p));
    while (q!=NULL){
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=NULL){
        q->data=A[i];
        q=q->next;
        i--;
    }
}
//Sliding Pointers
void Reverse2(struct Node *p){
    struct Node *q=NULL, *r=NULL;
    while (p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}

//recursive
void Reverse3(struct Node *q,struct Node *p){
    if(p){
        Reverse3(p,p->next);
        p->next=q;
    }
    else{
        first=q;
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
    int A[]={10,20,30,40,50};
    Create(A,5);

    Reverse3(NULL,first);
    Display(first);

    return 0;

}