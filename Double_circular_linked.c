#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
void creation(struct node *temp){
    struct node *temp1;
    int n;
    printf("enter number of nodes: ");
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        printf("enter data: ");
        scanf("%d",&temp->data);
        temp->next=malloc(sizeof(struct node));
        temp->next->prev=temp;
        temp=temp->next;
        temp->next=NULL;
    }
    printf("enter data: ");
    scanf("%d",&temp->data);
}
void print(struct node *start){
    struct node *temp=start;
     do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=start);
}
struct node* insert_at_beg(struct node *temp){
    struct node *temp1=malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&temp1->data);
    temp1->prev=NULL;
    temp1->next=temp;
    temp->prev=temp1;
    return temp1;
}
void insert_at_end(struct node *temp){
    struct node *temp1,*temp2;
    temp1=temp;
    while(temp1->next!=NULL){
        temp1=temp->next;
    }
    temp1->next=malloc(sizeof(struct node));
    printf("enter data: ");
    scanf("%d",&temp1->next->data);
    temp->next->next=NULL;
}
int main(){
    struct node *temp,*start=malloc(sizeof(struct node));
    // start->prev;
    // start->next=NULL;
    creation(start);
    temp=start;
    printf("jfwb");
    start=insert_at_beg(temp);
    temp=start;
    insert_at_end(temp);
    print(start);
    return 0;
}