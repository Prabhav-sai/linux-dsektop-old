#include<stdio.h>
int step(int i){
    if(i==0){
        return 1;
    }
    if(i==1){
        return 1;
    }
    return step(i-1)+step(i-2);
}
int main(){
    int n;
    scanf("%d",&n);
    printf("%d",step(n));
    return 0;
}