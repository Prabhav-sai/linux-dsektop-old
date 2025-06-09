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
char* sfind(int smalls[],char string[],int snum,int size){
    char* mins = (char*)malloc(size*sizeof(char*));
    char temp[size];
    strcpy(mins,string);
    for(int i=0;i<snum;i++){
        strcpy(temp,stringrot(string,smalls[i],size));
        int y =strcmp(temp,mins);
        if(y<0) strcpy(mins,temp);
    }
    return mins;
}
char* mfind(int bigs[],char string[],int bnum,int size){
    char* maxs = (char*)malloc(size*sizeof(char*));
    char temp[size];
    strcpy(maxs,string);
    for(int i=0;i<bnum;i++){
        strcpy(temp,stringrot(string,bigs[i],size));
        int y =strcmp(temp,maxs);
        if(y>0) strcpy(maxs,temp);
    }
    return maxs;
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
    int scount=0;
    int bcount=0;
    for(int i=0;i<size;i++){
        if(string[i]==small) scount++;
        if(string[i]==big) bcount++;
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
            bigs[bnum]=i;
            bnum++;
        }
    }
    char sanswer[size];
    char banswer[size];
    strcpy(sanswer,sfind(smalls,string,snum,size));
    strcpy(banswer,mfind(bigs,string,bnum,size));
    // printf("%s\n",string);
    printf("%s\n",sanswer);
    printf("%s\n",banswer);
    return 0;
}
// dazdbdzaaababaca i don't know why but this case doesn't work 
// i literally tried to debug this for 1/2 an hour because of this case but this is the only case it doesn't work
// for my bad luck that was first and only random test case i tried on my own bad luck ig