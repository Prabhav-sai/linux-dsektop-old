#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int ans=0;
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        ans=ans^temp;
        }
    printf("%d",ans);

    return 0;
}