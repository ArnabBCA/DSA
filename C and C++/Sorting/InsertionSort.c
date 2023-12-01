#include <stdio.h>

void Insertion(int A[],int n){
    int i,j,x;
    for(i=1;i<n;i++){          //because inserting starts from 1 because 0th index we are assuming already inserted
        j=i-1;
        x=A[i];
        while(j>-1 && A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}

int main(){
    int A[]={3,7,2,10},n=4,i;
    Insertion(A,n);
    for(i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    return 0;
}