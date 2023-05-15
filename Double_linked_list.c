#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
int creation(struct node *temp){
    int n;
    printf("enter number of nodes: ");
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        printf("enter the data: ");
        scanf("%d",&temp->data);
        temp->next=malloc(sizeof(struct node));
        temp->next->prev=temp;
        temp=temp->next;
        temp->next=NULL;
    }
    printf("enter the data: ");
    scanf("%d",&temp->data);
    return n;
}
void print(struct node *temp){
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
struct node* insert_at_beg(struct node *temp){
    temp->prev=malloc(sizeof(struct node));
    temp->prev->next=temp;
    temp=temp->prev;
    temp->prev=NULL;  
    printf("enter data: ");
    scanf("%d",&temp->data);
    return temp;
}
void insert_at_pos(struct node *temp,int pos){
    struct node *temp1;
    temp1=(struct node*)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d",&temp1->data);
    int i=1;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    if(temp->next==NULL){
        temp->next=temp1;
        temp1->prev=temp;
        temp1->next=NULL;
    }
    else{
    temp->next->prev=temp1;
    temp1->next=temp->next;
    temp1->prev=temp;
    temp->next=temp1;
    }
}
struct node* delete_at_beg(struct node *temp){
    struct node *temp1=malloc(sizeof(struct node));
    temp1=temp;
    temp=temp->next;
    temp->prev=NULL;
    free(temp1);
    return temp;
}
struct node* delete_at_pos(struct node *temp,int pos){
    struct node *temp1=malloc(sizeof(struct node));
    int i=1;
    while(i<pos){
        temp=temp->next;
        i++;
    }
    temp1=temp;
    temp->next->prev=temp->prev;
    temp->prev->next=temp->next;
    free(temp1);
}
void delete_at_end(struct node *temp){
    struct node *temp1=malloc(sizeof(struct node));
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp1=temp->next;
    temp->next=NULL;
    free(temp1);
}
void sorting(struct node *temp){
    struct node *temp1,*temp2;
    temp2=temp;
    for(temp1=temp;temp1!=NULL;temp1=temp1->next){
        for(temp2=temp1;temp2!=NULL;temp2=temp2->next){
            if(temp1->data>temp2->data){
                int  v=temp2->data;
                temp2->data=temp1->data;
                temp1->data=v;
            }
                 }
        }
    }
int main(){
    struct node *start=malloc(sizeof(struct node));
    struct node *temp;
    start->prev=NULL;
    start->next=NULL;
    temp=start;
    int n=creation(temp);
    temp=start;
    print(temp);
    temp=start;
    int c,c1;
    printf("1 for insertion \n2 for deletion\n3 for printing\n4 for sorting\n0 for exit: ");
    scanf("%d",&c);
    switch(c){
        case 1:
            printf("enter the position to insert: ");
            scanf("%d",&c1);
            if(c1==1)
            start=insert_at_beg(start);
            else{
                temp=start;
                insert_at_pos(temp,c1);
            }
            break;
        case 2:
            printf("enter the position to delete: ");
            scanf("%d",&c1);
            if(c1==1){
            start=delete_at_beg(start);
            }
            else if(c1==n){
                temp=start;
                delete_at_end(temp);
            }
            else{
                temp=start;
                delete_at_pos(temp,c1);
            }
            break;
        case 3:
            temp=start;
            sorting(temp);
            break;
    }
    temp=start;
    print(temp);
     return 0;
}