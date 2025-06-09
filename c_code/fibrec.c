#include <stdio.h>

int fib_num(int n) {
    if (n == 0 || n == 1) return n;
    return fib_num(n - 1) + fib_num(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);
		
		for (int i = 0; i < n; i++) {
        printf("%d ", fib_num(i));
    }
    printf("\n");
    return 0;
}