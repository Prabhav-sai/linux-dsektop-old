#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int flag=0;
    int count=0;
    for(int i=0;i<n;i++){
        for(int k=0;k<n-i;k++){
            for(int j=i+k,l=i;j>=i,l<=i+k;j--,l++){
                    if(arr[j]!=arr[l]){
                        flag=1;
                        break;
                    }
            }
            if(flag!=1){
                count++;
            }
            else{
                flag=0;
            }
        }
    }
    printf("%d",count);
    return 0;
}