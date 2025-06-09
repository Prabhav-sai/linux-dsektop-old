#include<stdio.h>
int main(){
    int n;
    int flag;
    scanf("%d",&n);
    for(int i=2;i<=n;i++){
        flag=0;
        for(int j=2;j<i;j++){
            if(i%j==0){
                flag=1;
                break;
            }
        }
        if(flag==1){
            continue;
        }
       printf("%d ",i);
    }
    
    return 0;
}