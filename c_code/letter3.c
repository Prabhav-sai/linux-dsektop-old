#include<stdio.h>
#include<string.h>
char* sortin(char string[],int l,int r){
    for(int i=l;i<r;i++){
        for(int j=i+1;j<r;j++){
            if(string[j]<string[i]){
                char temp = string[j];
                string[j]=string[i];
                string[i]=temp;
            }
        }
    }
    return string;
}
int fact(int n){
    int fact=1;
    for(int i=1;i<n+1;i++){
        fact=fact*i;
    }
    return fact;
}
void swap(char* a,char* b){
    char temp;
    temp =*a;
    *a=*b;
    *b=temp;
}
void permute(char string[],int length){
    char char1;
    int l;
    int flag=0;
    for(int i=length-1;i>0;i--){
        if(string[i-1]<string[i]){
            char1 = string[i-1];
            l=i-1;
            flag=1;
            break;
        }
    }
    if(flag!=1) return;
    char char2;
    int r;
    for(int i=length-1;i>l;i--){
        if(char1<string[i]){
            char2 =string[i];
            r =i;
            break;
        }
    }
    swap(&string[l],&string[r]);
    sortin(string,l+1,length);
    printf("%s\n",string);
    permute(string,length);
}
int main(){
    char string[8];
    scanf("%s",string);
    int length =strlen(string);
    int size = fact(length);
    int unique[27]={};
    int use;
    for(int i=0;i<length;i++){
        use=(int)(string[i]-96);
        unique[use]++;
    }
    int product=1;
    for(int i=1;i<27;i++){
        if(unique[i]!=0){
            product=product*fact(unique[i]);
        }
    }
    int ans=size/product;
    printf("%d\n",ans);
    sortin(string,0,length);
    printf("%s\n",string);
    permute(string,length);
    return 0;
}