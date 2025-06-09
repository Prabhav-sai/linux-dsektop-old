#include<stdio.h>
#include<string.h>
int number=1;
int fact(int n){
    int fact=1;
    for(int i=1;i<n+1;i++){
        fact=fact*i;
    }
    return fact;
}
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
void swap(char* a,char* b){
    char temp;
    temp =*a;
    *a=*b;
    *b=temp;
}
int compare(char*a,char*b,int count){
    int flag =0;
    for(int i=0;i<count;i++){
        if((a+i)!=(b+i)){
            flag=1;
        }
    }
    return flag;
}
void permute(char* a, int l ,int count){
    if(l==count){
        printf("%s",a);
    }
    for(int i=l;i<count;i++){
        swap((a + l), (a + i));
        sortin(a,l+1,i);
        permute(a, l + 1, count);
        //backtrack 
        swap((a + l), (a + i)); 
    }
    return;
}
int main(){
    char string[8];
    int count =0;
    for(int i=0;i<8;i++){
        char temp;
        scanf("%c",&temp);
        int n=(int)temp;
        string[i]=temp;
        if(n==10)break;
        count++;
    }
    for(int i=0;i<count;i++){
        for(int j=i+1;j<count;j++){
            int a=(int)string[i];
            int b=(int)string[j];
            if(b<a){
                char temp = string[j];
                string[j]=string[i];
                string[i]=temp;
            }
        }
    }
    permute(string,0,count);
    
   // printf("%s",string);
    return 0;
}