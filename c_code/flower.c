#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);

    int sum=0;
    int y=99999999;
    if(n%2==0){
        for(int i=0;i<n;i++){
            int temp;
            scanf("%d",&temp);
            if(temp%2==0){
                temp -=1;
            }
            sum=sum+temp;
            if(y>temp){
                y=temp;
            }
        }
        sum=sum-y;
        printf("%d",sum);

    }
    else{
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        if(temp%2==0){
            temp -=1;
        }
        sum=sum+temp;
    }
    printf("%d",sum);
    }

    return 0;
}