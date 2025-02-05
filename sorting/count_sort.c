#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void print_array(int *A, int n){
    for(int i = 0; i < n; i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}
int maximum(int *A, int n){
    int max = INT_MIN;
    for(int i = 0; i < n; i++){
        if(A[i] > max){
            max = A[i];
        }
    }
    return max;
}

//performing count sort
void count_sort(int* A, int n){
    int max = maximum(A,n);
    int* B = (int*)malloc((max+1)*sizeof(int));
    for(int i = 0; i < max+1; i++){
        B[i] = 0;
    }
    for(int i = 0; i < n; i++){
        B[A[i]] = B[A[i]] + 1;
    }
    int i = 0;
    int j = 0;
    while(i <= max){
        if(B[i] > 0){
            A[j] = i;
            B[i] = B[i] - 1;
            j++;
        }
        else{
            i++;
        }
    }
}
int main(){
    int A[] = {4,7,9,1,2,1,3,4};
    int n = 8;
    printf("array before sorting is: ");
    print_array(A,n);
    printf("array after sorting is: ");
    count_sort(A,n);
    print_array(A,n);
    return 0;
} 