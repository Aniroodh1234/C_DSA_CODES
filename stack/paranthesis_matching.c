#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int size;
    char* arr;
};
int stack_underflow(struct stack*ptr){
    if(ptr -> top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int stack_overflow(struct stack*ptr){
    if(ptr->top == ptr-> size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack* ptr, char exp){
    if(stack_overflow(ptr)){
        printf("stack overflow");
    }
    else{
        ptr -> top++;
        ptr -> arr[ptr->top] = exp;
    }
}

int pop(struct stack* ptr, char exp){
    if(stack_underflow(ptr)){
        printf("stack underflow");
    }
    else{
        int value = ptr -> arr[ptr -> top];
        ptr -> top --;
        return value;
    }
}
char paranthesis_match(char* exp){
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s -> top = -1;
    s -> size = 100;
    s ->arr = (char*)malloc(s -> size*sizeof(char));

    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i]=='('){
            push(s,exp[i]);
        }
        else if(exp[i]==')'){
            if(stack_underflow(s)){
                return 0;
            }
            else{
                pop(s,exp[i]);
            }
        }
    }
    if(stack_underflow(s)){
        return 1;
    }
    else{
        return 0;
    }


}
int main(){
    char* exp = "7*8(8*(4)^3)0";
    if(paranthesis_match(exp)){
        printf("expression is balanced\n");
    }
    else{
        printf("expression is not balanced");
    }
    return 0;
}