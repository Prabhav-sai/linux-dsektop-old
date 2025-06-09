#include<stdio.h>
int* count(){
    static count =0;
    int* p=&count;
//    count++;
 //   printf("%d\n",count);
    return p;
}
int main(){
    count();
    printf("%d\n",count);
    int * p=count();
    printf("%d\n",count);
    printf("%d",p);
    return 0;
}