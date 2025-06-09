#include <stdio.h>

int main(){

    int x;
    printf("Enter your number here=");
    scanf("%d",&x);
    int digit;
    int reveresednumber =0;
    int remainder;

    while(x){
        remainder=x%10;
        reveresednumber=reveresednumber*10+remainder;

        x=x/10;
        digit++;
    }
    printf("no of digits in the number=%d", digit);
    printf("\nreversed number = %d",reveresednumber);


    return 0;
}