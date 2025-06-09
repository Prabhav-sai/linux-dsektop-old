#include<stdio.h> 
int main(){ FILE * fptr; char s[10]; scanf("%s",s);char ans[1000000];scanf("%s",ans);fptr = fopen(s,"a");fprintf(fptr,"%s",ans);fclose(fptr);return 0;}
