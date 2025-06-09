#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int sum=0,count=0;
    for(int i=0;i<n;i++){
        int k;
        scanf("%d",&k);
        if(k>0){
            sum=sum+k;
        }
        if(k<0){
            if(sum==0){
                count++;
            }
            if(sum>0){
                sum -=1;
            }
        }
        
    }
    printf("%d",count);
    return 0;
}