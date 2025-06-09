#include<stdio.h>
#include<string.h>
int main(){
    char string[1000000];
    scanf("%s",string);
    int n = strlen(string);
    int flag = 0;
    int i=0,j=n-1;
    int k = n;
    while(k--){
        if(string[i]=='a'){
            i++;
        }
        if(string[j]=='a'){
            j--;
        }
    }
    if(n-1-j<i){
        flag=1;
    }
    int a=i,b=j;
    for(i=a,j=b;i<=b,j>=a;i++,j--){
        if(string[i]!=string[j]){
            // if(string[i]=='a'){
            //     j++;
            // }
            // else if(string[j]=='a'){
            //     i--;
            // }
            // else{
                flag = 1;
                break;
            // }
        }
    }
    if(flag==0){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}