#include"stdio.h"
int check(int x,char s[],int i,int h){
    if(x==h) return 1;
    int a = 0;
    if(s[i]==s[i+1]){
       a = check(x+1,s,i+1,h);
    }
    return a;
}
int main(){
    int n , h;
    char newline;
    scanf("%d %d%c",&n,&h,&newline);
    char s[n];
    int a[26]={};
    for(int i=0;i<n;i++){
        scanf("%c",&s[i]);
    }
    // for(int i=0;i<n;i++){
    //     printf("%c",s[i]);
    // }
    for(int i=0;i<n-h+1;i++){
        // if(h==1){
        //     printf("%c\n",s[i]);
        //     a[s[i]-'a']++;
        // }
        // for(int k=1;k<h;k++){
        //     if(s[i]!=s[i+k]){
        //         break;
        //     }
        //     if(k==h-1){
        //         i+=h-1;
        //         a[s[i]-'a']++;
        //     }
        // }
        if(check(1,s,i,h)==1){
            // printf("%d\n",i);
            a[s[i]-'a']++;
            i+=h-1;
        }
    }
    int max=0;
    for(int i=0;i<26;i++){
        if(a[i]>max) max = a[i];
    }
    // for(int i =0;i<26;i++){
    //     if(a[i]!=0){
    //         printf("%d %d\n",i,a[i]);
    //     }
    // }
    printf("%d",max);
    return 0;
}