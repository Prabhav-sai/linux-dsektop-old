#include<stdio.h>
int max(int sum,int* a,int n,int i,int dp[]){
    if(i>=n)return 0;
    sum=a[i];
    if(dp[i]!=-1)return dp[i];
    i = sum+i;
    return sum + max(sum,a,n,i,dp);
}
int main(){
    int n;
    scanf("%d",&n);
    int out[n];
    for(int i=0;i<n;i++){
        out[i]=0;
    }
    int sum=0;
    for(int i=0;i<n;i++){
        int a;
        scanf("%d",&a);
        int b[a];
    int dp[a];
    for(int i=0;i<a;i++){
        dp[i]=-1;
    }
        for(int j=0;j<a;j++){
            scanf("%d",&b[j]);
        }
        for(int k=a-1;k>=0;k--){
            sum=0;
            int temp =max(sum,b,a,k,dp);
            dp[k]=temp;
            if(temp>out[i]){
                out[i]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d\n",out[i]);
    }
    return 0;
}