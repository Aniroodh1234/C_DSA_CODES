#include<stdio.h>

void print_array(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

// applying insertion sort
void insertion_sort(int* A, int n){
    for(int i = 1; i <= n-1; i++){
        int key = A[i];
        int j = i-1;
        while(j >= 0 && A[j] > key){
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
}
int main(){
    int A[] = {4,7,9,1,2,1,3,4};
    int n = 8;
    printf("array before sorting is: ");
    print_array(A,n);
    printf("array after sorting is: ");
    insertion_sort(A,n);
    print_array(A,n);
    return 0;
} 