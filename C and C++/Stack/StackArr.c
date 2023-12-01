#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st){
    printf("Enter Size");
    scanf("%d",&st->size);
    st->top=-1;
    st->S=(int *)malloc(st->size*sizeof(int));
}

void Display(struct Stack st){
    int i;
    for(i=st.top;i>=0;i--){
        printf("%d ",st.S[i]);
    }
}

void push(struct Stack *st,int x){
    if(st->top==st->size-1){
        printf("Stack Overflow\n");
    }
    else{ 
        st->top++;
        st->S[st->top]=x;   
    }
}
int pop(struct Stack *st){
    int x=-1;    //if the stack is empty it will return -1
    if(st->top==-1){
        printf("Stck Underflow\n");
    }
    else{
        x=st->S[st->top--];
    }
    return x;
}

int peek(struct Stack st,int index){
    int x=-1;    //if it is returning -1 then value is not found
    if(st.top-index+1<0){    //if index is less than 0 then invalid position
        printf("Invalid index\n");
    }
    x=st.S[st.top-index+1];
    return x;
}

int isEmpty(struct Stack st){
    if(st.top==-1){
        return 1;
    }
    return 0;
}

int isFull(struct Stack st){
    return st.top==st.size-1;
}

int stackTop(struct Stack st){
    if(!isEmpty(st)){
        return st.S[st.top];
    }
    return -1; //the stack is empty
}

int main() {
    struct Stack st;

    // Create a stack
    create(&st);

    // Push values onto the stack using a for loop
    push(&st,23);
    push(&st,26);
    push(&st,25);

    printf("Element %d\n",stackTop(st));
    /*if(isEmpty(st)){
        printf("Stack is Empty");
    }
    else{
        printf("Stack is NOT empty");
    }*/

    // Display the contents of the stack
    printf("Stack contents: ");
    Display(st);

    return 0;
}
