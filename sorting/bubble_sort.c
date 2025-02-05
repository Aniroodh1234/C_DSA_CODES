#include<stdio.h>
void print_array(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

//printing bubble sort
void bubble_sort(int* A, int n){
    for(int i = 0; i < n-1; i++){
        for(int j =0; j <= n-1-i; j++){
            int temp;
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

//printing adaptive bubble sort --> it means if a array is already sorted there is no need for extra swaps and comparisions
void adaptive_bubble_sort(int* A, int n){
    int sorted = 0;
    for(int i = 0; i < n-1; i++){
        sorted = 1;
        for(int j =0; j <= n-1-i; j++){
            int temp;
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
                sorted = 0;
            }
        }
        if(sorted){
            return;
        }
    }
}
int main(){
    int A[] = {4,7,9,1,2,1,3,4};
    // int A[] = {1,2,3,4,5,6};
    int n = 8;
    printf("array before sorting is: ");
    print_array(A,n);
    printf("array after sorting is: ");
    bubble_sort(A,n);
    // adaptive_bubble_sort(A,n);
    print_array(A,n);
    return 0;
}