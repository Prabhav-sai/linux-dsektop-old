#include<stdio.h>
#include<stdlib.h>// header file to include malloc function
int main(){
    int* ptr;
    ptr=(int*)malloc(10*sizeof(int));
    for(int i=0;i<10;i++){
        scanf("%d",&ptr[i]);
    }
    printf("\n");
    for(int i=9;i>-1;i--){
        printf("%d ",*(ptr+i));
    }
    free(ptr);

    return 0;
}