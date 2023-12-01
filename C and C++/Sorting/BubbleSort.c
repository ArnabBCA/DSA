#include <stdio.h>
#include <stdlib.h>

struct Array {
    int *arr;
    int size;
};

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Bubble(struct Array *arr) {
    int i, j, flag = 0;
    for (i = 0; i < arr->size - 1; i++) {
        flag = 0;
        for (j = 0; j < arr->size - 1 - i; j++) {
            if (arr->arr[j] > arr->arr[j + 1]) {
                swap(&arr->arr[j], &arr->arr[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0) {
            break;
        }
    }
}

void display(struct Array *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("%d ", arr->arr[i]);
    }
    printf("\n");
}

int main() {
    struct Array myArray;

    printf("Enter the number of elements: ");
    scanf("%d", &myArray.size);

    myArray.arr = (int *)malloc(myArray.size * sizeof(int));

    printf("Enter the elements:\n");
    for (int i = 0; i < myArray.size; i++) {
        scanf("%d", &myArray.arr[i]);
    }

    Bubble(&myArray);

    printf("Sorted array:\n");
    display(&myArray);

    return 0;
}

/*void swap(int *x,int *y){
    int temp=*x;
    *x=*y;
    *y=temp;
}

void Bubble(int A[],int n){
    int i,j,flag=0;
    for(i=0;i<n-1;i++){          //because n-1 passes are required
        flag=0;
        for(j=0;j<n-1-i;j++){    //if there is 5 elements only 4 comparison is made and -i for reduce one comparision on next pass
            if(A[j]>A[j+1]){
                swap(&A[j],&A[j+1]);
                flag=1;
            }
        }
        if(flag==0){
            break;
        }
    }
}

int main(){
    int A[]={3,7,9,10},n=4,i;

    Bubble(A,4);
    for(i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    return 0;
}*/
