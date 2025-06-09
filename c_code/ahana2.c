#include <stdio.h>
#include <string.h>
#define MAX 500001
void strrev(char* str)
{
    
    int i = 0;
    int j = strlen(str) - 1;
 
    
    while (i < j) {
        char c = str[i];
        str[i] = str[j];
        str[j] = c;
        i++;
        j--;
    }
}

int main(){
    char str[MAX];
    scanf("%s",str);
    int m;
    scanf("%d",&m);
    int rig=0;
    for(int i=0;i<m;i++){
        int q1,q2;
        char a;
        scanf("%d",&q1);
        if(q1==1){
            rig++; 
            //printf("%s\n",str);
        }
        else{
            scanf("%d %c",&q2,&a);
            if((q2==1 && rig%2==0) || (q2==2 && rig%2==1)){
                int len= strlen(str);
                char arr[2]={a,'\0'};
                strncat(arr,str,len);
                // strncpy(str,arr,len+1);
                
                //printf("%s\n",str);

            }
            else{
               int len= strlen(str);
                char arr[2]={a,'\0'};
                strncat(str,arr,1);
                
                //strncpy(str,arr,len+1);
                //printf("%s\n",str); 
            }
            
        }
    }
    if(rig%2==1)
    strrev(str);
    printf("%s",str);
    return 0;
}