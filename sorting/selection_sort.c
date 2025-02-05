#include<stdio.h>

void print_array(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

//performing selection sort
void selection_sort(int* A, int n){
    int minimum, temp;
    for(int i = 0; i < n-1; i++){
        minimum = i;
        for(int j = i+1; j < n; j++){
            if(A[j] < A[minimum]){
                minimum = j;
            }
            temp = A[i];
            A[i] = A[minimum];
            A[minimum] = temp;
        }
    }
}

int main(){
    int A[] = {4,7,9,1,2,1,3,4};
    int n = 8;
    printf("array before sorting is: ");
    print_array(A,n);
    printf("array after sorting is: ");
    selection_sort(A,n);
    print_array(A,n);
    return 0;
} 