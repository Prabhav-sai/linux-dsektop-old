#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n+1];
    for(int i=1;i<n+1;i++){
        arr[i]=0;
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            if(i*j>n&i*j!=1){
                break;
            }
            arr[i*j]=1-arr[i*j];
        }
    }
    for(int i=1;i<n+1;i++){
        if(arr[i]==1){
            printf("%d ",i);
        }
    }

    return 0;
}