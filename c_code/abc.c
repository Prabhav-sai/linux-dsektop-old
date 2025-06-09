#include<stdio.h>
int main(){
    int a=1281;
    char* p=&a;
    *(p+(int)"0")=0;
    printf("%d",a);
    return 0;
}