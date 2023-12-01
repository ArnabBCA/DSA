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
//Count length
int Count(struct Node *p){  //Iterative     time=o(n), space=o(1) 
    int len=0;
    while(p){
        len++;
        p=p->next;
    }
    return len;
}
//Displaying
void Display(struct Node *p){ //Iterative
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
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

int main(){
    int A[]={3,5,7,10,25,8,32,2};
    Create(A,8);

    printf("Deleted Element %d\n",Delete(first,2));

    Display(first);
    return 0;
}