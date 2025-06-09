#include<stdio.h>
int main(){
    int n;
    char newline;
    scanf("%d%c",&n,&newline);
    char ans[n];
    int check=0;
    for(int i=0;i<n;i++){
        scanf("%c",&ans[i]);
        if(ans[i]=='"')check++;
        if(ans[i]==','&&check%2==0){
            ans[i]='*';
        }
    }
    for(int i=0;i<n;i++){
        printf("%c",ans[i]);
    }
    return 0;
}