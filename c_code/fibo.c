#include<stdio.h>
int fibo(int i){
    int a,b;
    if(i==0){
        return 0;
    }
    if(i==1){
        return 1;
    }
    a=fibo(i-1);
//    printf("%d ",a);
    b=fibo(i-2);
  //  printf("%d ",b);
 //   printf("%d ",a+b);
    return a+b;
}
int main(){
    int i;
    scanf("%d",&i);
    printf("%d",fibo(i));
    return 0;
}