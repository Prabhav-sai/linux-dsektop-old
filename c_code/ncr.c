#include<stdio.h>
int factorial(int x){
    int fac=1;
    for(int i=1;i<=x;i++){
        fac=fac*i;
    }
    return fac;
}
int comb(int n,int r){
    int nf=factorial(n);
    int rf=factorial(r);
    n=n-r;
    int nrf=factorial(n);
    int ncr=nf/(rf*nrf);
    return ncr;
}
int main(){
    int i,j;
    scanf("%d %d",&i ,&j);
    int f=comb(i,j);
    printf("%d\n",f);
    return 0;
}