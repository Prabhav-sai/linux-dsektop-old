#include <stdio.h>

#define MOD 1000000007
 int moves[4][2] = {{1, 2}, {1, -2}, {2, 1}, {2, -1}};

int isMinion(int x, int y, int k, int minions[][2]) {
   for (int i = 0; i < k; i++)
       if (minions[i][0] == x && minions[i][1] == y) return 1;
    return 0;
} 

 int isValid(int x, int y, int n, int m) {
    return x >= 0 && x < n && y >= 0 && y < m;
 }

 long long int countPaths(int x, int y, int n, int m, int k, int minions[][2]) {
    if (x == n - 1) return 1;
    long long int totalPaths = 0;
     for (int i = 0; i < 4; i++) {
        int newX = x + moves[i][0], newY = y + moves[i][1];
         if (isValid(newX, newY, n, m) && !isMinion(newX, newY, k, minions))
            totalPaths += countPaths(newX, newY, n, m, k, minions) % MOD;
    }
     return totalPaths;
 }

 int main() {
     int n, m, k; 
    scanf("%d %d %d",&n,&m,&k);
    int minions[k][2];
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<2;j++)
        {
            scanf("%d",&minions[i][j]);
        }
    }
    for(int i=0;i<k;i++)
    {
        for(int j=0;j<2;j++)
        {
            minions[i][j]=minions[i][j]-1;
        }
    }    
     
    long long int result;
    int j;
     for (j = 0; j < m; j++){
         result = 0;
        
         if (!isMinion(0, j, k, minions))
             result = countPaths(0, j, n, m, k, minions) % MOD;
        printf("%lld ",result);
     }
    return 0;
 }