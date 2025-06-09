#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int m=1;
    int space=n*2;
            for(int j=0;j<space+2;j++){
            printf(" ");
        }
    printf("1\n");
    n-=1;
    for(int i=1;i<n+1;i++){
        for(int j=0;j<space;j++){
            printf(" ");
        }
        int l=1;
        for(int a=1;a<=i;a++){
                l=l*a;
            }
        printf("1");
        for(int k=1;k<=i;k++){
            int ik=1;
            int kf=1;
            int b=i-k;
            for(int a=1;a<=k;a++){
                kf=kf*a;
            }
            for(int a=1;a<=b;a++){
                ik=ik*a;
            }

            int ick=l/(ik*kf);
            printf("   %d",ick);

        }
        space -=2;
        printf("\n");
    }
}