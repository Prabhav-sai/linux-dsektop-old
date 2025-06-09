#include<stdio.h>
int binary(int input,int n){
    int t=input;
    if(t==0)n-=1;
    for(int i=0;i<n;i++){
        if(t==0){
            printf("0");
        }
        else{
            t=t/2;
        }
    }
    if(input!=0){
    int temp=input;
    int count=0;
    for(int i=0;temp!=0;i++){
        temp >>=1;
        count++;
    }
    for(int j=0;j<count;j++){
        int output=input;
        output >>=count - j-1;
        output=output&1;
        printf("%d",output);
    }
    }
    else{
        printf("0");
    }

    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    int k=1;
    k <<= n;
    int arr[k];
    int flag=0;
    arr[0]=0;
    for(int i=1;i<k;i++){
        for(int l=0;l<n;l++){
        int p=1;
        p <<=l;
        int temp= arr[i-1];
        temp=temp^p;
        for(int j=0;j<i-1;j++){
            if(temp==arr[j]){
                flag=1;
                break;
            }
        }
        if(flag==1){
            flag =0;
        }
        else{
        arr[i]=temp;
        break;
        }
        }
    }
    for(int i=0;i<k;i++){
        binary(arr[i],n);
        printf("\n");
    }


    return 0;
}