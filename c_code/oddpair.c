#include<stdio.h>
int main(){
    int n;
    scanf("%d\n",&n);
    int array[n];
    for(int i=0;i<n;i++){
        scanf("%d",&array[i]);
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(array[i]==array[j]&&i<j){
                array[i]=0;
                array[j]=0;
                break;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(array[i]!=0){
            printf("%d",array[i]);
        }
    }
    
    return 0;
}