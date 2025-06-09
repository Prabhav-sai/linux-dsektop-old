#include<stdio.h>
int main(){
    int nu;
    scanf("%d",&nu);
    int ans[nu];
    for(int k=0;k<nu;k++){
        ans[k]=0;
        int flag=0;
        int check1[150]={};
        int check2[150]={};
        int checkt[150]={};
        int n;
        scanf("%d",&n);
        char arr1[n],arr2[n];
        scanf("%s",arr1);
        scanf("%s",arr2);
        for(int i=0;i<n;i++){
            int a=arr1[i];
            int b=arr2[i];
            check1[a]++;
            check2[b]++;
            checkt[a]++;
        }
        for(int i=97;i<=103;i++){
            // if(i==64) continue;
            if(check1[i]>=check2[i]){
                check1[i]-=check2[i];
            }
            else{
                check1[i]=0;
            }
            // if(check1[i]<0) check1[i] = 0-check1[i];
            if(check1[i]<=check2[i]){
                check2[i]-=checkt[i];
            }
            else{
                check2[i]=0;
            }
            // if(check2[i]<0) check2[i] = 0-check2[i];
        }
        for(int i=104;i<=122;i++){
            if(check1[i]!=check2[i]){
                flag=1;
                break;
            }
        }
        if(flag==1) continue;
        int a=0,b=0;
        for(int i=80;i<=103;i++){
            a+=check1[i];
            b+=check2[i];
        }
        check2[64]-=a;
        check1[64]-=b;
        // printf("%d %d\n",check1[64],check2[64]);
        if(check1[64]==check2[64]&&check1[64]>=0) ans[k]=1;
        else ans[k]=0;
    }
    for(int i=0;i<nu;i++){
        if(ans[i]==0) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}