#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
}*top=NULL;
void push(){
    if(top==NULL){
        struct node *temp=malloc(sizeof(struct node));
        printf("enter the data: ");
        scanf("%d",&temp->data);
        top=temp;
        temp->next=NULL;
    }
    else{
    struct node *temp;
    temp=malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d",&temp->data);
    temp->next=top;
    top=temp;
    }
}
struct node* pop(){
    struct node *temp1;
    temp1=top;
    top=top->next;
    free(temp1);
    return top;
}
void peep(int c){
    int i=1,n;
    struct node *temp1=top;
    printf("enter the position: ");
    scanf("%d",&n);
    if(c>n){
        if(temp1->next!=NULL){
        temp1=temp1->next;
        i++;
    }
    printf("%d\n",temp1->data);
    }
    else
        printf("enter vaid position");
}
void print(){
    struct node *temp=top;
    for(temp;temp!=NULL;temp=temp->next)
    printf("|%d|\n",temp->data);
    printf(" --");
}
int main(){
    // top=malloc(sizeof(struct node));
    int c=1;
    int k=0;
    while(c){
        printf("press 1 to push,2 to pop,3 to peep,4 for print,0 to exit: ");
        scanf("%d",&c);
        switch(c){
            case 1:
                push();
                k++;
                break;
            case 2:
                top=pop();
                break;
            case 3:
                peep(k);
                break;
            case 4:
                print();
                printf("\n");
                break;
        }
    }
return 0;
}