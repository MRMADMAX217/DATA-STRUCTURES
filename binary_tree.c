#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
void inorder(struct node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}
void preorder(struct node *root){
    if(root==NULL){
        return;
    }
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}
struct node *create(){
    int d;
    struct node *temp=malloc(sizeof(struct node));
    printf("enter -1 for no child,enter the data: ");
    scanf("%d",&d);
    if(d==-1) return NULL;
    temp->data=d;
    printf("enter left for %d: \n",d);
    temp->left=create();
    printf("enter right for %d: \n",d);
    temp->right=create();
    return temp;
}
int main(){
    struct node *start=create();
    inorder(start);
    printf("\n");
    preorder(start);
    printf("\n");
    postorder(start);
    return 0;
}