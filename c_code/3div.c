#include<stdio.h>
int main(){
    int n,k;
    char a;
    int sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%c",&a);
        k='a'-48;
        sum=sum+k;
    }

    
    if (sum%3==0){
        printf("YES");
    }
    else {
        printf("NO");
    }
    
    return 0;
}