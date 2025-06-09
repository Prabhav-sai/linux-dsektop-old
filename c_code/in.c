#include<stdio.h>
int main(){
    int arr[100]={};//intialing array to zero
    for(int i=0;i<100;i++){
        char t;//dummy char
        scanf("%d%c",&arr[i],&t);
        int y= (int)(t);//typecasting to int
        if(y==10){//10 is ascii value of \n
            break;
        }
    }
    for(int i=0;i<100;i++){
        if( arr[i]==0){
            break;
        }
        printf("%d ",arr[i]);
    }
    return 0;
}