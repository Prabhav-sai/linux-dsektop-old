#include<stdio.h>
#include<string.h>
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    char string[n];
    int a[n], b[n] ,c[n];
    scanf("%s",string);
    for(int i=0;i<n;i++){
        int n=(int)(string[i]-'a');
        a[i]=n;
    }
    for(int i=0;i<n;i++){
        int n=(int)(string[i]-'a');
        int m=(int)('z'-string[i]);
        if(n>m)b[i]=n;
        else b[i]=m;
    }
    int sumb=0,suma=0;
    for(int i=0;i<n;i++){
        sumb=sumb+b[i];
        suma=suma+a[i];
    }
    int set;
    if(sumb<k)printf("-1");
    else{
        k=k-suma;
        if(k>=0){
        for(int i=n-1;i>=0;i--){
            set=b[i]-a[i];
            if(set>=k){
                c[i]=a[i]+k;
                k=0;
            }
            else {
                c[i]=a[i]+set;
                k=k-set;
            }
        }
        }
        else{
            k=0-k;
            for(int i=n-1;i>=0;i--){
            if(k>=a[i]){
                k=k-a[i];
                c[i]=0;
            }
            else{
                c[i]=a[i]-k;
                k=0;
            }
            }
        }
    for(int i=0;i<n;i++){
        if(a[i]>=c[i]){
            string[i]-=c[i];
        }
        else{
            string[i]+=c[i];
        }
    }
    printf("%s",string);
    }
    return 0;
}