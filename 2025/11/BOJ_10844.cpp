// BOJ 10844 - 쉬운 계단 수

#include <iostream>
#include <vector>
#define MOD 1000000000

using namespace std;

int solve(int n ){
    vector<vector<long long>> dp (n+1, vector<long long>(10, 1));
    
    dp[1][0] = 0;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j<10; j++){
            if(j == 0){
                dp[i][j] = dp[i - 1][j + 1] % MOD;
            }
            else if(j == 9){
                dp[i][j] = dp[i - 1][j - 1] % MOD;
            }
            else{
                dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % MOD;
            }
        }
    }
    
    long long result = 0;
    for(int i = 0; i<10 ;i++){
        result += dp[n][i] % MOD;
    }
    
    return result % MOD;
}

int main()
{
    int n;
    cin >> n;
    
    cout << solve(n);
    
    return 0;
}