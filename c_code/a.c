#include<stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int a[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int p[n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            p[i][j] = 0;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < n - i; j++) {
            if (a[i] == a[i + j]) {
                p[i][i + j] = 1;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            count += p[i][j];
        }
    }

    printf("%d\n", count);

    return 0;
}