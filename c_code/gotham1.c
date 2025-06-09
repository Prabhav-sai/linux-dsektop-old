#include<stdio.h>
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int xi[k],yi[k];
    for(int i=0;i<k;i++){
        scanf("%d %d",&xi[i],&yi[i]);
    }
    int num=1000000007;
    long long int grid[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0){
                grid[i][j]=1;
            }
            else{
                grid[i][j]=0;
            }
        }
    }
    for(int i=0;i<k;i++){
        grid[xi[i]-1][yi[i]-1]=-1;
    }
    long long int a,b,c,d;
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==-1)continue;
            a=0,b=0,c=0,d=0;
            if(i-1>=0){
                if(j-2>=0) a=grid[i-1][j-2];
                if(j+2<m)  b=grid[i-1][j+2];  
            }
            if(i-2>=0){
                if(j-1>=0) c=grid[i-2][j-1];
                if(j+1<m)  d=grid[i-2][j+1];
            }
            if(a<0) a=0;
            if(b<0) b=0;
            if(c<0) c=0;
            if(d<0) d=0;
            grid[i][j]=(a+b+c+d)%num;
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++){
    //         printf("%d ",grid[i][j]);
    //     }
    //     printf("\n");
    // }
    for(int j=0;j<m;j++){
        printf("%lld ",grid[n-1][j]);
    }
    return 0;
}