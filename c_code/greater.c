#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    int count=0;
    int k=0;
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        if(temp>k){
            arr[count]=temp;
            k=temp;
            count++;
        }
    }
    printf("%d\n",count);
    for(int i=0;i<count;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}