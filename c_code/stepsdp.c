#include<stdio.h>
int func(int i,int dp[]){
    if(i<=2)
    return dp[i]=i;
    if(dp[i]!=0){
        return dp[i];
    }
    return dp[i]=func(i-1,dp)+func(i-2,dp);
}
int main(){
    int i;
    scanf("%d",&i);
    int dp[46]={};
    printf("%d",func(i,dp));
    return 0;
}