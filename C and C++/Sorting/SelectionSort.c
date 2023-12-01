#include <stdio.h>

void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void Selection(int A[],int n){
    int i,j,k;
    for(i=0;i<n-1;i++){    //for n-1 passes
        for(j=k=i;j<n;j++){
            if(A[j]<A[k]){
                k=j;
            }
        }
        swap(&A[i],&A[k]);
    }
}

int main(){
    int A[]={3,7,2,10},n=4,i;
    Selection(A,n);
    for(i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    return 0;
}