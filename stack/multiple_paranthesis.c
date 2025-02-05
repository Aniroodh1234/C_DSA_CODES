#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top;
    int size;
    char* arr;
};
int stack_underflow(struct stack* ptr){
    if(ptr -> top == -1){
        return 1;
    }
    else{
        return 0;
    }
}

int stack_overflow(struct stack* ptr){
    if(ptr -> top == ptr -> size - 1){
        return 1;
    }
    else{
        return 0;
    }
}

void push(struct stack* ptr,  char exp){
    if(stack_overflow(ptr)){
        printf("the stack is overflow\n");
    }
    else{
        ptr -> top++;
        ptr -> arr[ptr -> top] = exp;
    }
}
char pop(struct stack* ptr){
    if(stack_underflow(ptr)){
        printf("stack is uderflow\n");
        return 0;
    }
    else{
        char value = ptr -> arr[ptr -> top];
        ptr -> top--;
        return value;
    }
}
int match_fun(char b, char a){
    if(a=='{'&& b=='}'){
        return 1;
    }
        if(a=='('&& b==')'){
        return 1;
    }
        if(a=='['&& b==']'){
        return 1;
    }
    else{
        return 0;
    }
}

char paranthesis_match(char* exp){
    int pop_element;
    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s -> top = -1;
    s -> size = 100;
    s -> arr = (char*)malloc(s -> size*sizeof(char));

    for(int i = 0; exp[i] != '\0'; i++){
        if(exp[i]=='('||exp[i]=='{'||exp[i]=='['){
            push(s,exp[i]);
        }
        else if(exp[i]==')'||exp[i]=='}'||exp[i]==']'){
            if(stack_underflow(s)){
                printf("stack underflow");
                return 0;
            }

            char pop_element = pop(s);
            if(!match_fun(exp[i],pop_element)){
                return  0;
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
    char* exp = "7*{8[8*(4)^3]+0";
    if(paranthesis_match(exp)){
        printf("balanced paranthesis condition");
    }
    else{
        printf("unbalanced condition");
    }
    return 0;
}