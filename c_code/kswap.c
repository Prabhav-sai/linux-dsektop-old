#include<stdio.h>
int main(){
    int x,y,k;
    scanf("%d %d %d",&x,&y,&k);
    int p=1;
    p <<=k;
    int ans=x-(x%p)+(y%p);
    printf("%d",ans);

    return 0;
}