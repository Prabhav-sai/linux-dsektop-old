#include<stdio.h>
int main(){
    int n;
    scanf("%d\n",&n);
    int array[n];
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    int min;
    for(int i=0;i<n-1;i++){
        min =i;
        
        for(int j=i+1;j<n;j++){
            if(array[min]>array[j]){
                min =j;
            }
        }
        if(min!=i){
                int temp= array[i];
                array[i]=array[min];
                array[min]=temp;
        }
    }
    for(int i=0;i<n;i++){
        printf("%d ",array[i]);
    }
    

    return 0;
}