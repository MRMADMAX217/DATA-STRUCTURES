#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node* creation(int n){
    struct node *start=malloc(sizeof(struct node));
    struct node *temp;
    temp=start;
    for(int i=1;i<n;i++){
        printf("enter the data: ");
        scanf("%d",&temp->data);
        temp->next=NULL;
        temp->next=malloc(sizeof(struct node));
        temp=temp->next;
    }
    printf("enter the data: ");
    scanf("%d",&temp->data);
    temp->next=start;
    return start;
};
void print(struct node *start){
    struct node *temp=start;
     do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=start);
}
void insert_at_end(struct node *temp){
    struct node *temp2,*temp1=malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d",&temp1->data);
    temp1->next=temp;
    temp2=temp;
    while(temp2->next!=temp){
        temp2=temp2->next;
    }
    temp2->next=temp1;
}
struct node* insert_at_beg(struct node *temp){
    struct node *temp2,*temp1=malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d",&temp1->data);
    temp1->next=temp;
    temp2=temp;
    while(temp2->next!=temp){
        temp2=temp2->next;
    }
    temp2->next=temp1;
    temp=temp1;
    return temp;
}
void insert_at_pos(struct node *temp){
    struct node *temp2,*temp1=malloc(sizeof(struct node));
    int n,i=1;
    temp2=temp;
    printf("enter the position: ");
    scanf("%d",&n);
    printf("enter the data: ");
    scanf("%d",&temp1->data);
    while(i<n){
        temp2=temp2->next;
        i++;
    }
    temp1->next=temp2->next;
    temp2->next=temp1;
}
void deletion_at_end(struct node *temp){
    struct node *temp1,*temp2;
    temp1=temp;
    while(temp1->next->next!=temp)
        temp1=temp->next;
    temp2=temp1->next;
    temp1->next=temp;
    free(temp2);
}
struct node* deletion_at_beg(struct node *temp){
    struct node *temp1,*temp2;
    temp1=temp;
    while(temp1->next->next!=temp)
        temp1=temp1->next;
    temp2=temp1->next;
    temp2->next=temp->next;
    free(temp);
    return temp2->next;
}
struct node* deletion_at_pos(struct node *temp){
    struct node *temp1,*temp2;
    int i=1,pos;
    temp1=temp;
    printf("enter the pos: ");
    scanf("%d",&pos);
    while(i<pos){
        temp1=temp1->next;
        i++;
    }
    temp1->next=temp1->next->next;
}
int main(){
    int n;
    printf("enter the number of nodes: ");
    scanf("%d",&n);
    struct node *temp,*start=creation(n);
    temp=start;
    print(temp);
    printf("\n");
    int c;
    while(c){
        printf("enter 1 for insertion at beg,2 for inserting at end,3 for insertion at pos,5 for del at beg,6 for del at end,7 for del at pos: ");
        scanf("%d",&c);
        switch(c){
            case 1:
                temp=start;
                start=insert_at_beg(temp);
                break;
            case 2:
                temp=start;
                insert_at_end(temp);
                break;
            case 3:
                temp=start;
                insert_at_pos(temp);
                break;
            case 4:
                temp=start;
                print(temp);
                printf("\n");
                break;
            case 5:
                temp=start;
                start=deletion_at_beg(temp);
                break;
            case 6:
                temp=start;
                deletion_at_end(temp);
                break;
            case 7:
                temp=start;
                deletion_at_pos(temp);
                break;
        }
    }
     return 0;
}