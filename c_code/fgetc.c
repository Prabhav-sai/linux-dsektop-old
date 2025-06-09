#include<stdio.h>
int main(){
    FILE* fptr;
    fptr = fopen("read.txt","r");
    char ch;
    ch = fgetc(fptr);
    while(ch!=EOF){
        putchar(ch);
        ch = fgetc(fptr);
    }
    fclose(fptr);
}