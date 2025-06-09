#include<stdio.h>
int main(){
    int a=5;
    int* pointer;
    pointer=&a;
    printf("value of a = %d\n",a);
    printf("address of a = %d\n",pointer);
    printf("derefferenced value at address of a = %d\n",*pointer);

    return 0;
}