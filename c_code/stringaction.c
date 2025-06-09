#include<stdio.h>
#include<string.h>
//  #include<s
int main(){
    char string[1000000];
    scanf("%s",string);
    int n = strlen(string);
    int a,b;
    int m;
    int check =0;
    scanf("%d",&m);
    while(m--){
        scanf("%d",&a);
        if(a==1)check++;
        char add;
        if(a==2){
            char temp;
            scanf("%d%c",&b,&temp);
            scanf("%c",&add);
            // printf("%d",check);
            if(check%2==1){
                if(b==2){
                    b=1;
                }
                else if(b==1){
                    b=2;
                }
            }
            if(b==1){
                for(int i = n ;i>0;i--){
                    string[i]=string[i-1];
                }
                // printf("beg\n");
                string[0]=add;
            }
            if(b==2){
                // string[n]=string[n-1];
                string[n]=add;
                // printf("end\n");
            }
            n++;
        }
        // printf("%s\n",string);
    }
    int temp;
    if(check%2==1){
        for(int i=0,j=n-1;i<j;i++,j--){
            temp = string[j];
            string[j] = string[i];
            string[i] = temp;
        }
    }
    printf("%s",string);
    return 0;
}