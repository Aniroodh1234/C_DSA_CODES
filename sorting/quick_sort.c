#include<stdio.h>
void print_array(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

int partition(int A[],int low, int high){
    int i = low + 1;
    int j = high;
    int pivot = A[low];
    int temp;

    do{
        while(A[i] <= pivot){
            i++;
        }
        while(A[j] > pivot){
            j--;
        }
        if(i<j){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }while(i<j);
0
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}


void quick_sort(int* A, int low, int high){
    int partition_index;
    if(low < high){
        partition_index = partition(A, low, high);
        quick_sort(A,low, partition_index - 1);
        quick_sort(A,partition_index + 1, high);
    }
}
int main(){
    int A[] = {4,7,9,1,2,1,3,4};
    int n = 8;
    printf("array before sorting is: ");
    print_array(A,n);
    printf("array after sorting is: ");
    quick_sort(A,0,n-1);
    print_array(A,n);
    return 0;
} 