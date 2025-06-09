#include<stdio.h>
int main(){
    int arr[5]={1,5,3,7,4};
    int* ptr;
    ptr=&arr; // *(arr+1)=arr[1]
    // in this case arr is a constant pointer to the memory address of the first element;
    printf("%d\n",*(ptr+2));
    printf("%d\n",*(arr+2));

    return 0;   
}