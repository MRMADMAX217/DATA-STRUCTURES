#include<stdio.h>
#include<stdlib.h>
struct node{
     int data;
     struct node *next;
};
struct node* creation(int n){
     struct node *start=malloc(sizeof(struct node));
     struct node*temp;
     temp=start;
     for(int i=1;i<n;i++){
          printf("enter the data: ");
          scanf("%d",&temp->data);
          temp->next=malloc(sizeof(struct node));
          temp=temp->next;
          temp->next=NULL;
     }
     printf("enter the data: ");
     scanf("%d",&temp->data);
     return start;
}
void print(struct node *temp){
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }     
}
struct node* insert_at_beg(struct node *temp){
     struct node *temp1=malloc(sizeof(struct node));
     printf("enter the data at beg : ");
     scanf("%d",&temp1->data);
     temp1->next=temp; 
     temp=temp1;
     return temp;
}
void insert_at_end(struct node *temp){
     struct node *temp1=malloc(sizeof(struct node));
     printf("enter the data at end : ");
     scanf("%d",&temp1->data);
     while(temp->next!=NULL){
          temp=temp->next;
     }
     temp->next=temp1;
     temp1->next=NULL;
}
void insert_at_mid(struct node *temp){
     int pos;
     printf("enter pos ");                    
     scanf("%d",&pos);
     int i=1;
     struct node *temp1=malloc(sizeof(struct node));
     printf("enter the data after pos ");
     scanf("%d",&temp1->data);
     while(i<pos){
          temp=temp->next;
          i++;  
     }
     temp1->next=temp->next;
     temp->next=temp1;
}
struct node* delete_at_beg(struct node *temp){
     struct node *temp1;
     temp1=temp;
     temp=temp->next;
     free(temp1);
     return temp;
}
void delete_at_end(struct node *temp){
     struct node *temp1;
     while(temp->next->next!=NULL){
          temp=temp->next;
     }
     temp1=temp->next;
     temp->next=NULL;
     free(temp1);
}
void delete_at_pos(struct node *temp){
     int pos;
     printf("enter the pos to be deleted: ");
     scanf("%d",&pos);
     struct node *temp1;
     int i=1;
     while(i<pos-1){
          temp=temp->next;
          i++;
     }
     temp1=temp->next;
     temp->next=temp->next->next;
     free(temp1);
}
void sorting(struct node *temp){
    struct node *temp1,*temp2;
    temp2=temp;
    for(temp1=temp;temp1!=NULL;temp1=temp1->next){
        for(temp2=temp;temp2!=NULL;temp2=temp2->next){
            if(temp1->data<temp2->data){
                int v=temp2->data;
                temp2->data=temp1->data;
                temp1->data=v;
            }
                 }
        }
    }
int main(){
     struct node *temp,*start;
     int n;
     printf("enter number of nodes: ");
     scanf("%d",&n);
     start=creation(n);
     int c;
     int c1,c2;
     printf("1 for insertion \n2 for deletion\n3 for printing\n4 for sorting\n0 for exit: ");
     scanf("%d",&c);
     while(c!=0){
     switch(c){
          case 1:
               printf("press 1 for insertion at beg\n2 for pos\n3 for end:: ");
               scanf("%d",&c1);
               switch(c1){
                    case 1:
                         start=insert_at_beg(temp);
                         break;
                    case 3:
                         temp=start;
                         insert_at_end(temp);
                         break;
                    case 2:
                         temp=start;
                         insert_at_mid(temp);
                         break;
               }
               break;
          case 2:{
               printf("press 1 for deletion at beg\n2 for pos\n3 for end: ");
               scanf("%d",&c2);
               switch(c2){
                    case 1:
                         start=delete_at_beg(temp);
                         break;
                    case 3:
                         temp=start;
                         delete_at_end(temp);
                         break;
                    case 2:
                         temp=start;
                         delete_at_pos(temp);
                         break;
               }
               break;
          }
          case 3:
               temp=start;
               print(temp);  
               break; 
          case 4:
               temp=start;
               sorting(temp);
               break;
     }
     printf("1 for insertion \n2 for deletion\n3 for printing\n0 for exit: ");
     scanf("%d",&c);
     }
     return 0;
}