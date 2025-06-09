#include<stdio.h>
#include<string.h>
int sort(char arr1[],char arr2[],int n,int k){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr1[i]>arr1[j]||arr1[j]=='@'){
                char temp = arr1[i];
                arr1[i]=arr1[j];
                arr1[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr2[i]>arr2[j]||arr2[j]=='@'){
                char temp = arr2[i];
                arr2[i]=arr2[j];
                arr2[j]=temp;
            }
        }
    }
    int ans= strncmp(arr1,arr2,n-1-k);
    if(ans!=0)ans=0;
    else ans =1;
    return ans;
}
int count(char arr[],int n){
    int count =0;
    for(int i=0;i<n;i++){
        if(arr[i]=='@') count++;
    }
}
int main(){
    int nu;
    int ans[nu];
    scanf("%d",&nu);
    for(int i=0;i<nu;i++){
        int n;
        scanf("%d",&n);
        char arr1[n],arr2[n];
        scanf("%s",arr1);
        scanf("%s",arr2);
        int k;
        int k1=count(arr1,n);
        int k2=count(arr1,n);
        if(k1>k2) k=k1;
        else k=k2;
        ans[i] = sort(arr1,arr2,n,k);
    }
    for(int i=0;i<nu;i++){
        if(ans[i]==0) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}