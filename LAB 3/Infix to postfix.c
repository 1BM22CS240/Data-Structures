#include<stdio.h>
#include<ctype.h>
#define MAX 5

int stack[MAX];
int top = -1;

int precedence(char c){
    if(c =='+' || c == '-'){
        return 1;
    }
    else if(c=='*' ||c=='/' ||c=='%'){
        return 2;
    }
    else{
        return 0;
    }
}

void push(int ele){
    if(top<MAX){
        top++;
        stack[top] = ele;
    }
}

int pop(){
    if(top!=-1){
        int popped = stack[top];
        top--;
        return popped;
    }
    return '\0';
}



void infix_to_postfix(char* exp){
    char result[100];
    int k =0;
    for(int i=0;exp[i]!='\0';i++){
        if(isalpha(exp[i])){
            result[k++] = exp[i];
        }
        else if(exp[i]=='('){
            push(exp[i]);
        }
        else if(exp[i]==')'){
            while(top!=-1 && stack[top]!='('){
                result[k++] = pop();
            }
            pop();
        }
        else{
            while(top!=-1 && precedence(stack[top])>=precedence(exp[i])){
                result[k++] = pop();
            }
            push(exp[i]);
        }
    }

    while(top!=-1){
        result[k++] = pop();
    }
    result[k] = '\0';
    for(int i=0;i<sizeof(result)/sizeof(result[0]);i++){
        exp[i] = result[i];
    }
}

int main(){
    char exp[10];
    gets(exp);
    infix_to_postfix(exp);
    puts(exp);
    return 1;
}
