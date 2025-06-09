#include<stdio.h>
int main(){
    int arr[100][100]={};
    int n;
    scanf("%d",&n);
    int input[n][4];
    for(int i=0;i<n;i++){
        scanf("%d %d %d %d",&input[i][0],&input[i][1],&input[i][2],&input[i][3]);
    }
    for(int i=0;i<n;i++){
        for(int j=input[i][0];j<input[i][1];j++){
            for(int k=input[i][2];k<input[i][3];k++){
                arr[j][k]=1;
            }
        }
    }

    int count=0;
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            if(arr[i][j]==1){
                count++;
            }
        }
    }
    printf("%d",count);
    return 0;
}