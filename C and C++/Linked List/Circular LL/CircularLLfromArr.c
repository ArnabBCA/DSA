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
    Head->data=A[0];   //for storing first element
    Head->next=Head;  //assign to hend because only one element
    last=Head; //for inserting new Node at the last

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
void RDisplay(struct Node *h){       //recursive
    static int flag=0;
    if(h!=Head || flag==0){
        flag=1;
        printf("%d ",h->data);
        RDisplay(h->next);
    }
    flag=0;
}


int main(){
    int A[]={2,3,4,5,6};
    Create(A,5);
    //printf("length is %d",Length(Head));
    Display(Head);
    //RDisplay(Head);

}