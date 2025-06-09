#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* stringrot(char* string,int n,int size){
    char* out = (char*)malloc(size*sizeof(char*));
    for(int i=n,j=0;i<size;i++,j++){
        out[j]=*(string+i);
    }
    for(int j=size-n,i=0;j<size;j++,i++){
        out[j]=*(string+i);
    }
    return out;
}
char* sfind(int smalls[],char string[],int num,int size){
    char* mins = (char*)malloc(size*sizeof(char*));
    char temp[size];
    strcpy(mins,string);
    for(int i=0;i<num;i++){
        strcpy(temp,stringrot(string,smalls[i],size));
        int y =strcmp(temp,mins);
        if(y<0) strcpy(mins,temp);
    }
    return mins;
}
char* mfind(int smalls[],char string[],int num,int size){
    char* mins = (char*)malloc(size*sizeof(char*));
    char temp[size];
    strcpy(mins,string);
    for(int i=0;i<num;i++){
        strcpy(temp,stringrot(string,smalls[i],size));
        int y =strcmp(temp,mins);
        if(y>0) strcpy(mins,temp);
    }
    return mins;
}
int main(){
    char string[1000];
    scanf("%s",string);
    int size = strlen(string);
    char small=string[0];
    char big=string[0];
    for(int i=0;i<size;i++){
        if(string[i]<small) small = string[i];
        if(string[i]>big) big = string[i];
    }
    int scount;
    int bcount;
    for(int i=0;i<size;i++){
        if(string[i]==small){
           scount++;
        }
        if(string[i]== big){ bcount++;
    }
    int smalls[scount];
    int bigs[bcount];
    int snum=0;
    int bnum=0;
    for(int i=0;i<size;i++){
        if(string[i]==small){
            smalls[snum]=i;
            snum++;
        }
        if(string[i]==big){
            bigs[bnum]==i;
            bnum++;
        }
    }
    strcpy(string,sfind(smalls,string,snum,size));
    printf("%s",string);
    return 0;
}