#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    int D;
    scanf("%d",&D);
    if(D==1){
    for(int i=0;i<n-1;i++){
        int temp = arr[i+1][0];
        arr[i+1][0]=arr[i][0];
        arr[i][0]=temp;
    }
    for(int j=0;j<n-1;j++){
        int temp = arr[n-1][j+1];
        arr[n-1][j+1]=arr[n-1][j];
        arr[n-1][j]=temp;
    }
    for(int i=n-1;i>0;i--){
        int temp = arr[i][n-1];
        arr[i][n-1]=arr[i-1][n-1];
        arr[i-1][n-1]=temp;
    }
    for(int j=n-1;j>1;j--){
        int temp = arr[0][j];
        arr[0][j]=arr[0][j-1];
        arr[0][j-1]=temp;
    }
    }
    else{
    for(int j=0;j<n-1;j++){
        int temp = arr[0][j+1];
        arr[0][j+1]=arr[0][j];
        arr[0][j]=temp;
    }
    for(int i=0;i<n-1;i++){
        int temp = arr[i+1][n-1];
        arr[i+1][n-1]=arr[i][n-1];
        arr[i][n-1]=temp;
    }
    for(int j=n-1;j>0;j--){
        int temp = arr[n-1][j];
        arr[n-1][j]=arr[n-1][j-1];
        arr[n-1][j-1]=temp;
    }
    for(int i=n-1;i>1;i--){
        int temp = arr[i][0];
        arr[i][0]=arr[i-1][0];
        arr[i-1][0]=temp;
    }

    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}