#include<stdio.h>
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int count,p,test;
    for(int i=30;i>-1;i--){
        count =0;
        p=1;
        p<<=i;
        for(int j=0;j<n;j++){
            test=a[j];
            test>>=i;
            test=test&1;
            if(test!=1){
                count++;
            }
        }
        if(count<=k){
        for(int j=0;j<n;j++){
            test=a[j];
            test>>=i;
            test=test&1;
            if(test!=1){
                a[j]=a[j]|p;
            }
        }
        }
        k=k-count;
    }
    int ans;
    for(int i=0;i<n;i++){
        ans=ans&a[i];
    }
    printf("%d",ans);
    return 0;
}