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
int partition(int a[],int beg,int end){
    int i=beg,j=end;
    int pivot=a[i];
    while(i<j){
        while(a[i]<=pivot)
            i++;
        while(a[j]>pivot)
            j--;
        if(i<j){
            int t=a[i];
            a[i]=a[j];
            a[j]=t;
        }
    }
    int t=a[beg];
    a[beg]=a[j];
    a[j]=t;
    return j;
}
void quick(int arr[],int beg,int end){
    if(beg<end){
        int p;
        p=partition(arr,beg,end);
        quick(arr,beg,p-1);
        quick(arr,p+1,end);
    }
}

int main(){
    int n;
    printf("enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    create(n,arr);
    quick(arr,0,n-1);
    print(arr,n);
    return 0;
}