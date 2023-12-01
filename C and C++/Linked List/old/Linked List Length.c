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

//Noo of nodes or Length of a Linked List

int count(struct Node*p){               //iterative
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}

int Rcount(struct Node*p){              //recursive
    if(p!=NULL){
        return Rcount(p->next)+1;
    }
    else{
        return 0;
    }
}

//Sum od elements in a Linked List

int sum(struct Node*p){                //iterative
    int sum=0;
    while(p!=NULL){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}


int Rsum(struct Node*p){                //iterative
    if(p==NULL){
        return 0;
    }
    else{
        return Rsum(p->next)+p->data;
    }
}

//Maximum no in a linked lists

int max(struct Node*p){                 //iterative
    int max= -32768;  //or INT32_MIN
    while(p){
        if(p->data>max){
            max=p->data;
        }
        p=p->next;
    }
    return max;
}

int Rmax(struct Node*p){
    int x=0;
    if(p==0){
        return -32768;
    }
    x=Rmax(p->next);
    if(x>p->data){
        return x;
    }
    else{
        return p->data;
    }
}



int main(){
    int A[]={3,5,7,10,15};
    create(A,5);
    //printf("length is %d",count(first));
    //printf("length is %d",Rcount(first));

    //printf("Sum is  %d",sum(first));
    //printf("Sum is  %d",Rsum(first));

    //printf("Max is %d",max(first));
    printf("Max is %d",Rmax(first));
    return 0;
}