#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int gain[n];
    int max=0;
    int sum=0;
    for(int i=0;i<n;i++){
        scanf("%d",&gain[i]);
    }
    for(int i=0;i<n;i++){
        sum=sum+gain[i];
        if(sum>max){
            max=sum;
        }
    }
    printf("%d",max);

    
    return 0;
}