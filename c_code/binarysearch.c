#include<stdio.h>
int binarysearch(int l,int r,int n,int A[],int size){
    if(l==r){
        // if(A[l]>=n)
        return l;
    }
    if(r==l+1){
        if(n<=A[l]) return l;
        if(n<=A[r]) return r;
        if(A[r]<n) return size;
    }
    int a=(l+r)/2;
    if(n<=A[a]){
        return binarysearch(l,a,n,A,size);
    }
    else if(n>A[a]){
        return binarysearch(a+1,r,n,A,size);
    }
    return size;
}
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    int A[n];
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    int Q[q];
    for(int i=0;i<q;i++){
        scanf("%d",&Q[i]);
    }
    for(int i=0;i<q;i++){
        printf("%d ",binarysearch(0,n-1,Q[i],A,n));
    }
    return 0;
}