#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node * next;
}*Head;

void Create(int A[],int n){
    int i;
    struct Node *t,*last;
    Head=(struct Node *)malloc(sizeof(struct Node));
    Head->data=A[0];
    Head->next=Head;
    last=Head;

    for(i=1;i<n;i++){
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }
}
//Find length of C_LL
int Length(struct Node *p){
    int len=0;
    do{
        len++;
        p=p->next;
    }while(p!=Head);
    return len;
}
//Displaying C_LL
void Display(struct Node *h){        //iterative
    do{
        printf("%d ",h->data);
        h=h->next;
    }while(h!=Head);
    printf("\n");
}

int Delete(struct Node *p,int index){
    struct Node *q;
    int i,x;
    if(index<0 || index>Length(Head)){
        return -1;                            //invalid index
    }
    if(index==1){                            //deleting head node
        while(p->next!=Head){           //to move to the last node
            p=p->next;
        }
        x=Head->data;           //to copy data and store
        if(Head==p){   //if it the only node or last node
            free(Head);
            Head=NULL;
        }
        else{  //it it is not last node
            p->next=Head->next;
            free(Head);
            Head=p->next;
        }
    }
    else{          //delete any node. similar to linear linked list
        for(i=0;i<index-2;i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}
int main(){
    int A[]={2,3,4,5,6};
    Create(A,5);

    Delete(Head,0);

    Display(Head);
    return 0;
}