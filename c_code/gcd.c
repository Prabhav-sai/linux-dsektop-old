#include<stdio.h>

int gcd(int a, int b){
    if(b>a){
        return gcd(a,b-a);
    }
    else if(a>b){
        return gcd(b,a-b);
    }
    else{
        return a;
    }
}

int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d",gcd(a,b));
    return 0;
}