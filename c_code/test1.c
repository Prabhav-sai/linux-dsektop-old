#include <stdio.h>
 
int main() {
		int arr[3][4] = {{10, 11, 12, 13},
                    {20, 21, 22, 23},
                    {30, 41, 32, 33}};

		int (*ptr)[3][4];
		ptr = &arr;
        int *p;
        p=&arr;
        int x=sizeof(arr);

		printf("%d %d %d\n", *ptr, *(ptr + 1), *(ptr + 2));
		printf("%d %d %d\n", **ptr, *(*ptr + 1), *(*ptr + 2));
		printf("%d %d %d\n", ***ptr, **(*ptr + 1), *(*(*ptr + 2) + 1));
        printf("%d\n",x);
        printf("%d %d %d %d\n",p,*p,*p+1,p+1);
		return 0;
}