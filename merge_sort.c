#include<stdio.h>
void create(int arr[],int n){
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
void sort(int a[],int beg,int mid,int end){
     int n1=mid-beg+1;
     int n2=end-mid;
     int la[n1],ra[n2];
     for(int i=0;i<n1;i++){
        la[i]=a[beg+i];
     }
     for(int j=0;j<n2;j++){
        ra[j]=a[mid+1+j];
     }
     int k=beg,i=0,j=0;
     while(i<n1&&j<n2){
        if(la[i]<ra[j]){
            a[k]=la[i];
            i++;
        }
        else{
            a[k]=ra[j];
            j++;
        }
        k++;
     }
     while(i<n1){
        a[k++]=la[i++];
     }
     while(j<n2) a[k++]=ra[j++];
}
void merge(int a[],int beg,int end){
    if(beg<end){
        int mid=(beg+end)/2;
        merge(a,beg,mid);
        merge(a,mid+1,end);
        sort(a,beg,mid,end);
    }
}

int main(){
    int n;
    printf("enter number of elements: ");
    scanf("%d",&n);
    int a[n];
    create(a,n);
    merge(a,0,n-1);
    print(a,n);
     return 0;
}