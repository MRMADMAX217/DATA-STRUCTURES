#include<stdio.h>
#include<stdlib.h>
struct node
{
    int num;
    struct node *next;
};
void creation(struct node *temp,int n){
    int m;
    for(int i=1;i<=n;i++){
        printf("enter the number :");
        scanf("%d",&m);
        temp->num=m;
        temp->next=(struct node*)malloc(sizeof(struct node));
        temp=temp->next;
        temp->next=NULL;
        }
    }
void print(struct node *temp){
    while(temp->next!=NULL){
        printf("%d\n",temp->num);
        temp=temp->next;
    }
}
struct node *insert_at_b(struct node *temp){
    struct node *new;
    new=(struct node*)malloc(sizeof(struct node));
    printf("enter the data: ");
    scanf("%d",&new->num);
    new->next=temp;
    temp=new;
    return temp;
}
void insert_at_mid(struct node *temp,int pos){
    int i=1;
    // struct node *temp2;
    // temp2=temp;
    while(i<pos){
        temp=temp->next;
    }
    printf("enter the data :");
    scanf("%d",&temp->num);
}
int main(){
    int a;
    struct node *temp,*temp2,*start;
    printf("enter number of nodes :");
    scanf("%d",&a);
    start=(struct node*)malloc(sizeof(struct node));
    start->next=NULL;
    struct node *temps=start;
    creation(temps,a);
    print(temps);
    int k;
    printf("enter 1 for insertion\n2 for deletion\n3 for exit");
    scanf("%d",&k);
    switch(k){
        case 1: {
            int b;
            printf("enter the position :");
            scanf("%d",&b);
            if(b==1){
                temps=insert_at_b(temps);
            }
            else{
                temps=start;
                insert_at_mid(temps,b);
            }
        }
    }
    temps=start;
    print(temps);
    temps=start;
    int c=0;
    while (temps!=NULL)
    {
        c++;
        temps=temps->next;
    }
    printf("nodes are %d",c);
    }