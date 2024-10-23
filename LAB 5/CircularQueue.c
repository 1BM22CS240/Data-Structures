#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int queue[MAX];
int f=-1,r=-1;

int isfull(){
    if(f==0 && r ==MAX-1 || f ==(r+1)%MAX) return 1;
    return 0;
}

int empty(){
    if(f==-1) return 1;
    return 0;
}

void enqueue(int val){
    if(isfull()){
        printf("the queue is full\n");
    }
    else{
        if(f==-1 && r==-1) f++;
        r = (r+1)%MAX;
        queue[r] = val;
        printf("%d has been added\n",val);
    }
}

void dequeue(){
    if(empty()){
        printf("the queue is empty\n");
    }
    else{
        int popped = queue[f];
        if(f==r) {
            f=0;
            r=0;
        }
        else{
            f = (f+1)%MAX;
        }
        printf("%d has been popped \n",popped);
    }
}

void display(){
    for(int i=f;i!=r;i=(i+1)%MAX){
        printf("%d ",queue[i]);
    }
    printf("%d ",queue[r]);
}

int main(){
    printf("1 enqueue\n");
    printf("2 dequeue\n");
    printf("3 check full\n");
    printf("4 check empty\n");
    printf("5 display\n");
    printf("6 exit\n");

    int is_work = 1;
    while(is_work){
        int n;
        scanf("%d",&n);
        if(n==1){
            int val;
            scanf("%d",&val);
            enqueue(val);
        }
        else if(n==2){
            dequeue();
        }
        else if(n==3){
            if(isfull()) printf("true");
            else printf("false");
        }
        else if(n==4){
            if(empty()) printf("true");
            else printf("false");
        }
        else if(n==5) display();
        else{
            is_work=0;
        }
    }

    return 0;
}