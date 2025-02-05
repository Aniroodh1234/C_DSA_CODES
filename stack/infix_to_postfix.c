#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int top;
    int size;
    char* arr;
};
char stacktop(struct stack* ptr){
    return ptr -> arr[ptr-> top];
}
int presendence(char ch){
    if(ch=='*'|| ch =='/'){
        return 3;
    }
    else if(ch == '+'|| ch =='-'){
        return 2;
    }
    else{
        return 0;
    }
}
int is_operator(char ch){
    if(ch =='+'|| ch=='*'|| ch=='/'||ch == '-'){
        return 1;
    }
    else{
        return 0;
    }
}
int stackunderflow(struct stack* ptr){
    if(ptr -> top == -1){
        return 1;
    }
    else{
        return 0;
    }
}
int stackoverflow(struct stack* ptr){
    if(ptr -> top == ptr -> size -1){
        return 1;

    }
    else{
        return 0;
    }
}
void push(struct stack* ptr, char p){
    if(stackoverflow(ptr)){
        printf("stack overflow");
    }
    else{
        ptr -> top++;
        ptr -> arr[ptr -> top] = p;
    }
}
char pop(struct stack* ptr){
    if(stackunderflow(ptr)){
        printf("stackunderflow");
        return -1;
    }
    else{
        char value = ptr -> arr[ptr ->top];
        ptr -> top--;
        return value;
    }
}
char* infix_to_postfix(char* infix){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s -> size = 100;
    s -> top = -1;
    s -> arr = (char*)malloc(s->size * sizeof(char));
    char* postfix = (char*)malloc((strlen(infix)+1) * sizeof(char));
    int i = 0;
    int j = 0;
    while(infix[i] != '\0'){
        if(!is_operator(infix[i])&&infix[i]!='('&&infix[i]!=')'){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else if(infix[i]=='('){
            push(s,infix[i]);
            i++;
        }
        else if(infix[i]==')'){
            while(stacktop(s)!='('){
                postfix[j]=pop(s);
                j++;
            }
            pop(s);
            i++;
        }
        else{
            if(presendence(infix[i]) > presendence(stacktop(s))){
                push(s,infix[i]);
                i++;
            }
            else{
                postfix[j] = pop(s);
                j++;
            }
        }
    }
    while(!stackunderflow(s)){
        postfix[j] = pop(s);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    char value;
    char* infix = "(m-n)*(p+q)";
    printf("postfix expression is %s",infix_to_postfix(infix));
    return 0;
}



// prime number
// #include<stdio.h>
// int main(){
//     int x;
//     int prime_no = 1;

//     printf("enter a number: ");
//     scanf("%d",&x);
//     if(x < 0 || x == 0){
//         printf("number is not a prime number\n");
//         return 0;
//     }
//     if(x==1){
//         printf("1 is neither prime nor composite\n");
//         return 0;
//     }
//     for(int i = 2; i < x; i++){
//         if(x % i == 0){
//             prime_no = 0;
//             printf("number is  not a prime number\n");
//             break;
//         }
//     }

//     if (prime_no) {
//         printf("Number is a prime number\n");
//     }

//     return 0;
// }


//print sum if even dighit in a given number

// #include<stdio.h>
// int main(){
//     int num;
//     int sum = 0;
//     int count = 0;
//     int x;
//     printf("enter the given set of number: ");
//     scanf("%d",&num);
//     while(num > 0){
//         x = num % 10;
//         if(x % 2 == 0){
//             sum = sum + x;
//             count++;
//         }
//         num = num / 10;
//     }
//     printf("the number of even digits in a given set of number is: %d\n", count);
//     printf("the sum of even digits in a given set of number is: %d", sum);
//     return 0;
// }


// reverse a number sequence 
// #include<stdio.h>
// int main(){
//     int temp,x,y;
//     int a[5] = {1,2,3,4,5};

//     printf("the sequence is: ");
//     for(int i = 0; i < 5; i++){
//         printf("%d ",a[i]);
//     }
//     int p = 0;
//     int q = 4; 
//     while(p < q){
        
//         temp = a[p];
//         a[p] = a[q];
//         a[q] = temp;

//         p++;
//         q--;
//     }
//     printf("\nthe reversed sequence is: ");
//     for(int i = 0; i <= 4; i++){
//         printf("%d ",a[i]);
//     }
//     return 0;
// }