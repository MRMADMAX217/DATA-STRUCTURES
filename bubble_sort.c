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
void bubble_sort(int a[],int n){
    int b[n];
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}
void select(int a[],int n){
    for(int i=0;i<n;i++){
        int key=a[i];
        int min=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        int t=a[i];
        a[i]=a[min];
        a[min]=t;
    }
}
int main(){
    int n;
    printf("enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    create(n,arr);
    select(arr,n);
    print(arr,n);
    return 0;
}