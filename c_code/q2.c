#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
typedef struct complexnumber{
    int size;
    float* number;
}complexnumber;
complexnumber ADD(complexnumber c1,complexnumber c2){
    complexnumber ans;
    ans.size=c1.size;
    ans.number=(float*)malloc(ans.size*sizeof(float));
    float a ,b;
    for(int i=0;i<c1.size;i++){
        a=*(c1.number+i);
        b=*(c2.number+i);
        *(ans.number+i)=a+b;
    }
    return ans;
}
complexnumber SUB(complexnumber c1,complexnumber c2){
    complexnumber ans;
    ans.size=c1.size;
    ans.number=(float*)malloc(ans.size*sizeof(float));
    for(int i=0;i<c1.size;i++){
        *(ans.number+i)=(*(c1.number+i))-(*(c2.number+i));
    }
    return ans;
}
float DOT(complexnumber c1,complexnumber c2){
    float ans=0;
    for(int i=0;i<c1.size;i++){
        ans +=(*(c1.number+i))*(*(c2.number+i));
    }
    return ans;
}
float MOD(complexnumber c1){
    float ans=0;
    float mul;
    for(int i=0;i<c1.size;i++){
        mul = *(c1.number+i);
        ans +=mul*mul;
    }
    ans = sqrt(ans);
    return ans;
}
float COSINE(complexnumber c1,complexnumber c2){
    float ans;
    ans = DOT(c1,c2);
    ans = ans/(MOD(c1)*MOD(c2));
    return ans;
}
void PrintComplex(complexnumber c1){
    for(int i=0;i<c1.size;i++){
        printf("%.2f ",*(c1.number+i));
    }
    return;
}
int main(){
    while(1){
    char* action;
    action = (char*)malloc(6*sizeof(char));
    int n;
    // printf("Input:\n");
    scanf("%s",action);
    if(strcmp(action,"-1")==0) break;
    int y=0;
    if(strcmp(action,"ADD")==0) y=1;
    if(strcmp(action,"SUB")==0) y=2;
    if(strcmp(action,"DOT")==0) y=3;
    if(strcmp(action,"COSINE")==0) y=4;
    if(y!=0){
    scanf("%d",&n);
    complexnumber c1;
    c1.size=n;
    c1.number=(float*)malloc(n*sizeof(float));
    for(int i=0;i<n;i++){
        scanf("%f",&(c1.number[i]));
    }
    complexnumber c2;
    c2.size=n;
    c2.number=(float*)malloc(n*sizeof(float));
    for(int i=0;i<n;i++){
        scanf("%f",&(c2.number[i]));
    }
    printf("Result: ");
    if(y==1){
        PrintComplex(ADD(c1,c2));
    }
    else if(y==2){
        PrintComplex(SUB(c1,c2));
    }
    else if(y==3){
        printf("%.2f",DOT(c1,c2));
    }
    else if(y==4){
        printf("%.2f",COSINE(c1,c2));
    }
    printf("\n\n");
    free(c1.number);
    free(c2.number);
    }
    free(action);
    // char check1,check2,newl;
    // scanf("%c%c",&newl,&check1);
    // if(check1=='-'){
    //     scanf("%c",&check2);
    //     if(check2=='1') break;
    // }
    }
    return 0;
}