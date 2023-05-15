#include<stdio.h>
int selection(int n,int a[]){
    int c[n];
    int u,i;
    for(i=0;i<n;i++){
        int min=i,j;
        for(j=i+1;j<n;j++){
            if(a[j]<a[min]){
            min=j;
        }
        }
        int temp= a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int b[10];
    int n;
    printf("enter the number of  elements : ");
    scanf("%d",&n);
    printf("enter the elements : \n");
    int i;
	for(i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    selection(n,b);
     return 0;
}
