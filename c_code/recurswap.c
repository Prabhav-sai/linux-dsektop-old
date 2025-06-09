#include<stdio.h>
void swap(char arr[4],int l,int r){
    if(l==r){
        for(int i=0;i<r;i++){
            printf("%c",arr[i]);
        }
    }
    for(int i=l;i<r;i++){
        char temp=arr[i];
        arr[i]=arr[l];
        arr[l]=temp;
        swap(arr[4],l+i,r);
        char tem=arr[i];
        arr[i]=arr[l];
        arr[l]=tem;
    }
    
}
int main(){
    int n=4;
    char a , b ,c;
    char letter[4]={a,a,b,c};
    swap(letter[4],0,n);
    return 0;
}