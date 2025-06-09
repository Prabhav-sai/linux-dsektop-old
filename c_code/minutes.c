#include<stdio.h>
int main(){
    float a,b,c;
    scanf("%f:%f:%f",&a,&b,&c);
    float min;
    min=a*60 + b + c/60;
    printf("%f",min);
    return 0;
}