#include<stdio.h>
int sum(int arr[],int l,int r){
    int sum=0;
    for(int i=l-1;i<r;i++){ 
        sum=sum+arr[i];
    }
    return sum;
}
int print(int arr[],int l,int r){
    for(int i=l-1;i<r;i++){ 
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}
int main(){
    int n,sum1;// l , r ;
    scanf("%d %d",&n,&sum1);
//    scanf("%d %d %d",&n,&l,&r);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(int l=0;l<=n;l++){
        for(int r=l;r<=n;r++){
            if(sum(arr,l,r)==sum1){
                print(arr,l,r);
            }
            else if(sum(arr,l,r)>sum1){
                break;
            }
        }
    }
    return 0;
}