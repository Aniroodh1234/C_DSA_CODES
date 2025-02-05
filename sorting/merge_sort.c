#include<stdio.h>
void print_array(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
void merge(int* A, int mid, int low, int high){
    int i = 0;
    int j = mid +1;
    int k = 0;
    int B[100];
    while(i <= mid && j <= high){
        if(A[i] < A[j]){
            B[k] = A[i];
            i++;
            k++;
        }
        else{
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while(i <= mid){
        B[k] = A[i];
        i++;
        k++;
    }
    while(j <= high){
        B[k] = A[j];
        j++;
        k++;
    }
        for(int i = 0; i<= high; i++){
        A[i] = B[i];
    }
}

void merge_sort(int* A, int low, int high){
    int mid;
    mid = (high + low)/2;
    if(low < high){
        merge_sort(A,low,mid);
        merge_sort(A,mid+1,high);
        merge(A,mid, low, high);
    }
}
int main(){
    int A[] = {4,7,9,1,2,1,3,4};
    int n = 8;
    printf("array before sorting is: ");
    print_array(A,n);
    printf("array after sorting is: ");
    merge_sort(A,0,n-1);
    print_array(A,n);
    return 0;
} 