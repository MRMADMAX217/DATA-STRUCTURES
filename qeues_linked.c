#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*front,*rear;
void enque(){
    if(rear==NULL&&front==NULL){
        rear=malloc(sizeof(struct node));
        printf("enter data: ");
        scanf("%d",&rear->data);
        front=rear;
    }
    else{
        rear->next=malloc(sizeof(struct node));
        rear=rear->next;
        printf("enter data: ");
        scanf("%d",&rear->data);
        rear->next=NULL;
    }
}
void deque(){
    struct node *temp2;
    temp2=front;
    front=front->next;
    free(temp2);
}
void print(){
    struct node *temp;
    for(temp=front;temp->next!=NULL;temp=temp->next)
        printf("%d ",temp->data);
}
int main(){
    int n=1,i=1;
    rear=NULL;
    front=NULL;
    printf("press 1 for push,2 for pop,3 for peep,4 for print: ");
    scanf("%d",&n);
    while(n){
        switch(n){
            case 1:
                enque();
                break;
            case 2:
                deque();
                break;
            case 4:
                print();
                printf("\n");
                break;
        }  
        printf("press 1 for push,2 for pop,3 for peep: ");
        scanf("%d",&n); 
    }
    // print();
    return 0;
}