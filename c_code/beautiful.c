#include<stdio.h>
int main(){
    int string[100];
    int count=0;
    int flag1=0,flag2=0;
    for(int i=0;i<100;i++){
        char temp;
        scanf("%c",&temp);
        int n =(int)temp;
        if(n==10)break;
        if(temp>64&&temp<91)flag1=1;
        if(temp>96&&temp<123)flag2=1;
        string[i]=temp;
        count++;
    }
    int flag =0;
    for(int i=0;i<count;i++){
        for(int j=i+1;j<count;j++){
            if(string[i]==string[j]){
                flag =1;
                break;
            }
        }
        if(flag==1)break;
        
    }
    if(flag1==0||flag2==0)flag=1;
    if(flag==1){
        printf("No");
    }
    else{
        printf("Yes");
    }

    return 0;
}