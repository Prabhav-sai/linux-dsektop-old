#include<stdio.h>
int binaryseach(int l,int r,int arr[],int n,int size){
    if(n<=arr[0])return 0;
    if(n>arr[size-1])return size;
    int mid =(l+r)/2;
    if(r==l) return l;
    if(r==l+1){
        if(n<=arr[l]) return l;
        if(n<=arr[r]) return r;
    }
    if(n<=arr[mid]) return binaryseach(l,mid,arr,n,size);
    return binaryseach(mid+1,r,arr,n,size);
}
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    int arr[n],Q[q];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int i=0;i<q;i++){
        scanf("%d",&Q[i]);
    }
    for(int i=0;i<q;i++){
        printf("%d ",binaryseach(0,n-1,arr,Q[i],n));
    }
    return 0;
}