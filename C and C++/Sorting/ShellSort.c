#include <stdio.h>

void ShellSort(int A[],int n){
    int gap,i,j,temp;
    for(gap=n/2;gap>=1;gap/=2){
        for(i=gap;i<n;i++){
            temp=A[i];
            j=i-gap;
            while(j>=0 && A[j]>temp){
                A[j+gap]=A[j];
                j=j-gap;
            }
            A[j+gap]=temp;
        }
    }
}


int main(){
    int A[]={15,7,12,10},n=4,i;

    ShellSort(A,4);
    for(i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    return 0;
}