#include<stdio.h>
void swap(int a,int b){
    int temp =a;
    a=b;
    b=temp;
}
void swap2(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int x=10;
    int y =11;
    printf("before swap x=%d y=%d",x,y);
    swap(x,y);
    printf("\nbefore swap x=%d y=%d",x,y);
    swap2(&x,&y);
    printf("\nbefore swap2 x=%d y=%d",x,y);
    return 0;
}