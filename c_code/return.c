#include<stdio.h>
int ret(int a,int b){
    int retu[2];
    retu[0]=b;
    retu[1]=a;
    return retu;
}
int main(){
    printf("%d",ret(1,2));
    return 0;
}