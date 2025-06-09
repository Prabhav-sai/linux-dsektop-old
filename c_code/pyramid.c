#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int space=n*2;
    int m=1;
    int p=1;
    for(int i=0;i<n;i++){
        for(int k=0;k<space;k++){
          printf(" ");
        }

        for(int j=0;j<m;j++){

            printf("   %d",p);
            p++;
            if(j==m-1){
                printf("\n");
            }
        }
        space -=2;
        m++;
    }

    return 0;
}