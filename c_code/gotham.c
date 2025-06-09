#include<stdio.h>
long long int grid[1001][1001];
    int num=1000000007;
long long int number(int x,int y,int n,int m,int k,int xi[],int yi[]){
    if(x<=0||y<=0||y>m)return 0;
    if(grid[x-1][y-1]!=-1)return grid[x-1][y-1];
    if(x==1)return 1;
    for(int i=0;i<k;i++){
        if(x==xi[i]&&y==yi[i])return 0;
    }
    long long int b = number(x-1,y-2,n,m,k,xi,yi)%num;
    if(b!=0) grid[x-2][y-3]=b;
    long long int c = number(x-1,y+2,n,m,k,xi,yi)%num;
    if(c!=0) grid[x-2][y+1]=c;
    long long int d = number(x-2,y-1,n,m,k,xi,yi)%num;
    if(d!=0) grid[x-3][y-2]=d;
    long long int e = number(x-2,y+1,n,m,k,xi,yi)%num;
    if(e!=0) grid[x-3][y]=e;
    return grid[x-1][y-1]=(b+c+d+e)%num;
}
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int xi[k],yi[k];
    for(int i=0;i<k;i++){
        scanf("%d %d",&xi[i],&yi[i]);
    }
    for(int i=0;i<1001;i++){
        for(int j=0;j<1001;j++){
            grid[i][j]=-1;
        }
    }
    for(int i=1;i<m+1;i++){
    int s =number(n,i,n,m,k,xi,yi);
    long long int answer = s%num;
    printf("%lld ",answer);
    }
    return 0;
}