#include<stdio.h>
typedef struct
{
    int length;
    int breadth;
}rect;

int main(){
    rect r1;
    r1.length =10;
    r1.breadth = 15;
    printf("%d %d %d",r1.length,r1,r1.breadth);   
    return 0;
}