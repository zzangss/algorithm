// BOJ 1301 - 비즈공예 

#include <iostream>
#include <cstring>

using namespace std;

long long dp[6][6][11][11][11][11][11];

long long solve(int prev, int cur, int a, int b, int c, int d, int e){
    if(a == 0 && b == 0 && c == 0 && d == 0 && e == 0){
        return 1;
    }
    
    if(dp[prev][cur][a][b][c][d][e] != -1){
        return dp[prev][cur][a][b][c][d][e];
    }
    
    dp[prev][cur][a][b][c][d][e] = 0;
    
    if(a > 0 && prev!=0 && cur!=0) dp[prev][cur][a][b][c][d][e] += solve(cur, 0, a-1, b, c, d, e);
    if(b > 0 && prev!=1 && cur!=1) dp[prev][cur][a][b][c][d][e] += solve(cur, 1, a, b - 1, c, d, e);
    if(c > 0 && prev!=2 && cur!=2) dp[prev][cur][a][b][c][d][e] += solve(cur, 2, a, b, c-1, d, e);
    if(d > 0 && prev!=3 && cur!=3) dp[prev][cur][a][b][c][d][e] += solve(cur, 3, a, b, c, d-1, e);
    if(e > 0 && prev!=4 && cur!=4) dp[prev][cur][a][b][c][d][e] += solve(cur, 4, a, b, c, d, e-1);

    return dp[prev][cur][a][b][c][d][e];
}

int main()
{
    int n;
    cin >> n;
    
    int beads[5] = {0};
    for(int i = 0; i<n; i++){
        int k; 
        cin >> k;
        beads[i] = k;
    }
    memset(dp, -1, sizeof(dp));
    
    cout << solve(5,5, beads[0], beads[1], beads[2], beads[3], beads[4]);
    
    return 0;
}