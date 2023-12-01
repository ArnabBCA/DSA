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
        t=(struct Node *)malloc(sizeof(struct Node));
        t ->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
//Displaying
void Display(struct Node *p){ //Iterative
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
void RDisplay(struct Node *p){ //Recursice
    if(p!=NULL){
        RDisplay(p->next);
        printf("%d ",p->data);
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
int RCount(struct Node *p){  //Recursive    time=o(n), space=o(n)
    if(p!=NULL){
        return RCount(p->next)+1;
    }
    else{
        return 0;
    }
}
//Sum of elements
int Sum(struct Node *p){ //Iterative
    int s=0;
    while(p!=NULL){
        s+=p->data;
        p=p->next;
    }
    return s;
}
int RSum(struct Node *p){ //Recursive   time=o(n), space=o(n)
    if(p==NULL){
        return 0;
    }
    else{
        return RSum(p->next)+p->data;
    }
}
//Maximum element
int Max(struct Node*p){ //Iterative
    int max=INT_MIN;
    while(p){
        if(p->data>max){
            max=p->data;
        }
        else{
            p=p->next;
        }
    }
    return max;
}
int RMax(struct Node *p){ //recursive
    int max=0;
    if(p==0){
        return INT_MIN;
    }
    max=RMax(p->next);
    if(max>p->data){
        return max;
    }
    else{
        return p->data;
    }
}

//check whether ll is sorted in assending order
int isSorted(struct Node *p){
    int x=p->data;      // or int x=-65536;
    while(p!=NULL){
        if(p->data<x){
            return 0;
        }
        x=p->data;
        p=p->next;
    }
    return 1;
}
//remove duplicated from a sorted ll
void RemoveDuplicate(struct Node *p){
    struct Node *q=p->next;   
    while(q!=NULL){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

//Check for loop in a ll
int isLoop(struct Node *f){
    struct Node *p,*q;
    p=q=f;
    do{
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    }while(p && p!=q);
    if(p==q){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    //struct Node *temp;
    //struct Node *t1,*t2;
    int A[]={3,5,7,10,10,25,32};
    Create(A,7);
    //printf("Length is %d",(RCount(first)))
    //printf("Sum is %d",(RSum(first)));
    /*if(isSorted(first)){
        printf("Sorted");
    }
    else{
        printf("Not Sorted");
    }*/
    //RemoveDuplicate(first);

    /*t1=first->next->next;
    t2=first->next->next->next->next;
    t2->next=t1;
    printf("%d\n",isLoop(first));*/

    
    //Display(first);
    return 0;
}