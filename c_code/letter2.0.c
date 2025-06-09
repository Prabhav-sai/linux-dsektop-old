#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int fact(int n){
    int fact=1;
    for(int i=1;i<n+1;i++){
        fact=fact*i;
    }
    return fact;
}
void swap(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
}
void permute(char** a, int l ,int count){
    static int i=0;
    if(l==count){
        strcpy(a[i],*a);
        i++;
    }
    for(int i=l;i<count;i++){
        swap((*a + l), (*a + i)); 
        permute(a, l + 1, count);   
        //backtrack 
        swap((*a + l), (*a + i)); 
    }
    return;
}
/* void sort(char** strings,int size,int length){
    if(size==0) return ;
    for(int i=1;i<size;i++){
        if(strcmp(strings[i],strings[i-1])<0){
            char temp[length];
            strcpy(temp,strings[i]);
            strcpy(strings[i],strings[i-1]);
            strcpy(strings[i-1],temp);
        }
        if(strcmp(strings[i],strings[i-1])==0){
            char temp[length];
            for(int j=0;j<size;j++){
                temp[j]='z';
            }
            strcpy(strings[i],temp);
        }  
    }
    sort(strings,size-1,length);
    return ;
} */
int main(){
    char string[8];
    scanf("%s",string);
    int length =strlen(string);
    char **strings;
    int size = fact(length);//size is number of possible strings
    strings = (char **)malloc(size * sizeof(char *));
    for(int i=0;i<size;i++){
        strings[i]=(char*)malloc(length * sizeof(char));
    }
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
    strcpy(strings[0],string);
    permute(strings,0,length);
//    sort(strings,size,length);
 /*   char check[length];
    for(int i=0;i<size;i++){
        check[i]='z';
    }*/
    int ans=size/product;
    printf("%d\n",ans);
    for(int size1=size;size1>0;size1--)
    for(int i=1;i<size1;i++){
        if(strcmp(strings[i],strings[i-1])<0){
            char temp[length];
            strcpy(temp,strings[i]);
            strcpy(strings[i],strings[i-1]);
            strcpy(strings[i-1],temp);
        }
    }
    for(int i=0;i<size;i+=product){
      //  if(strcmp(strings[i],check)!=0)        
        printf("%s\n",strings[i]);
    }

    return 0;
}