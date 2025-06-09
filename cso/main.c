#include<stdio.h>
#include"foo.h"

int main(){
    // int i;
    printf("This is a shared library test\n");
    foo();
    return 0;
}