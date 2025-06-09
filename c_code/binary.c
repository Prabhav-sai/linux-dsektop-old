#include<stdio.h>
int main(){
    int input;
    scanf("%d",&input);
    if(input!=0){
    int temp=input;
    int count=0;
    for(int i=0;temp!=0;i++){
        temp >>=1;
        count++;
    }
    for(int j=0;j<count;j++){
        int output=input;
        output >>=count - j-1;
        output=output&1;
        printf("%d",output);
    }
    }
    else{
        printf("0");
    }

    return 0;
}