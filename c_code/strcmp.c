#include<stdio.h>
#include<string.h>
int main(){
    char string[]={'a','b','c','\0'};
    char s[]={};
    scanf("%s",s);
    // printf("%s",string);
    // strcpy(string,s);
    if(strcmp(string,s)==0){
        printf("10\n");
    }
    else{
        printf("00\n");
    }
}