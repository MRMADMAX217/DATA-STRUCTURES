#include<stdio.h>
#define MAX 5
int stack[MAX];
int top=-1;
void push(int ele){
    if(top==MAX-1){
        printf("stack is fulled ");
        return; 
    }
    top++;
    stack[top]=ele;
}
void pop(){
    top--;
}
int peep(){
    int pos;
    printf("enter the required position: ");
    scanf("%d",&pos);
    return stack[pos];
}
void print(){
    for(int i=0;i<top+1;i++){
        printf("%d ",stack[i]);
    }
}
int main(){
    int ele;
    int c=1;
    while(c){
        printf("press 1 to push,2 to pop,3 to peep,4 for print,0 to exit: ");
        scanf("%d",&c);
    switch(c){
        case 1:
            printf("enter the element: ");
            scanf("%d",&ele);
            push(ele);
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("required data is %d",peep());
            break;
        case 4:
            print();
    }
    }

    return 0;
}