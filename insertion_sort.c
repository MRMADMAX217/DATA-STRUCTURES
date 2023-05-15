#include<stdio.h>
void create(int n,int arr[]){
    for(int i=0;i<n;i++){
        printf("enter element: ");
        scanf("%d",&arr[i]);
    }
}
void print(int a[],int n){
    for(int i=0;i<n;i++){
    printf("%d\t",a[i]);
    }
}
void insert(int a[],int n){
    for(int i=1;i<n;i++){
        int key=a[i];
        int j=i-1;
        while(key<a[j]&&j>=0){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    create(n,a);
    insert(a,n);
    print(a,n);
    return 0;
}
