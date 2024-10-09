#include<stdio.h>
#define MAX 5

int stack[MAX];
int top = -1;

void push(int num){
    if(top == MAX-1){
        printf(" OVERFLOW \n");
    }
    else{
        top++;
        stack[top] = num;
        printf("\nThe pushed number is %d\n",num);
    }
}

void pop(){
    if(top==-1)
    {
        printf("Underflow! Stack is Empty!\n");
    }
    else
    {
        int numpop = stack[top];
        top--;
        printf("\nThe popped number is %d\n",numpop);
    }
}

void display(){
    if(top == -1)
    {
        printf("The Stack is Empty!\n");
    }
    else
    {
        for(int i=0;i<=top;i++)
        {
            printf("\n \t Display--->  %d \n\n",stack[i]);
        }
    }
}

int main(){
    push(1);
    push(2);
    display();
    pop();
    display();
    push(3);
    push(4);
    push(5);
    pop();
    display();
    pop();
    pop();
    display();
    pop();
    pop();
    pop();
    pop();

}






























