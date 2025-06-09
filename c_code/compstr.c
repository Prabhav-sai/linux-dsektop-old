#include<stdio.h>
int main(){
    int a[2][2]={{1,2},{3,4}};
    int b[2][2]={{1,2},{3,4}};
    if(**a==**b){
        printf("1");
    }
    else printf("0");
    return 0;
}