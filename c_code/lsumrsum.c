#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int lsum,rsum,flag=0;
    for(int i=1;i<n-1;i++){
        lsum=0;
        rsum=0;
        for(int j=0;j<i;j++){
            lsum+=arr[j];
        }
        for(int k=i+1;k<n;k++){
            rsum+=arr[k];
        }
        if(lsum==rsum){
            printf("%d",i);
            flag=1;
            break;
        }
        
    }
    if(flag!=1){
        printf("-1");
    }

    return 0;
}