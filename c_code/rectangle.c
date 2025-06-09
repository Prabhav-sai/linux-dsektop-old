#include <stdio.h>

int main() {
    int width,breadth;
    scanf("%d %d",&width,&breadth);
    width -=2;
    breadth -=2;
    printf("o");
    for(int i=0;i<width;i++){
        printf("-");
    }
    if(width>=0){printf("o");}
    for(int j=0;j<breadth;j++){
        printf("\n|");
        for(int i=0;i<width;i++){
        printf(" ");
    }
    if(width>=0){printf("|");}
    
    }
       if(breadth>=0){ printf("\no");
    for(int i=0;i<width;i++){
        printf("-");
    }
   if(width>=0){printf("o");}    }

    return 0;
}