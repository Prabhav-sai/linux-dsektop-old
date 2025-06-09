#include<stdio.h>
int findclosest(int position,int list[],int k,int B[]){
    int distance[k+1];
    for(int i=1;i<=k&&position-i>0;i++){
        distance[i]=list[position]-list[position-i];
        if(distance[i]<0) distance[i]=0-distance[i];
    }
    int min=distance[1]+B[position-1];
    int howmany=1;
    for(int i=1;i<=k&&position-i>0;i++){
        if(distance[i]+B[position-i]<=min){
            min=distance[i]+B[position-i];
            howmany=i;
        }
    }
    return min ;
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int A[n+1];
    for(int i=1;i<n+1;i++){
        scanf("%d",&A[i]);
    }
    int B[n+1];
    B[1]=0;
    for(int i=2;i<n+1;i++){
        B[i]=findclosest(i,A,k,B);
        // printf("%d",B[i]);
    }
    printf("%d",B[n]);
    return 0;
}