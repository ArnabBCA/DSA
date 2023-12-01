#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void Create(int A[],int n){
    int i;
    struct Node *t,*last;
    first=(struct Node *)malloc(sizeof(struct Node));   //creating a new Node
    first -> data=A[0];
    first -> next=NULL;             //because it is first node there is nothing to assign
    last=first;                    //same as above

    for(i=1;i<n;i++){           //from 1 because 0th node is already created above
        t=(struct Node *)malloc(sizeof(struct Node));
        t ->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;          //moves to t and becomes a new node
    }
}

//Displaying
void Display(struct Node *p){               //Iterative
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
}
void RDisplay(struct Node *p){             //recursive
    if(p!=NULL){
        //printf("%d ",p->data);   //to print not in reverse order
        RDisplay(p->next);
        printf("%d ",p->data);  //to print in reverse because of returning time
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
//Insering
void Insert(struct Node *p,int index,int x){
    struct Node *t;
    int i;

    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index<0|| index>Count(p)){  //if invalid Index
        return;
    }
    if(index==0){  //to insert before first node
        t->next=first;
        first=t;
    }
    else{       //to insert affter a given index
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}


int main(){
    int A[]={3,5,7,10,25,8,32,2};
    Create(A,8);

    //Insert(first,0,10);

    RDisplay(first);
    return 0;
}