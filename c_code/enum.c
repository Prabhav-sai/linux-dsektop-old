#include "stdio.h"

typedef enum Weekday {
    Sunday = 5, 
    Monday = 3, 
    Tuesday, 
    Wednesday = 2, 
    Thursday, 
    Friday, 
    Saturday
} Weekday;

int main() {
    Weekday today;
    scanf("%s",&today);
    printf("Day %d\n",today+1);
    printf("Size of enum variable = %d bytes", 
            sizeof(today));	
    return 0 ;
}