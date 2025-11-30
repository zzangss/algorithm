// BOJ 12865 - 평범한 배낭

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(vector<pair<int,int>> thing, int n, int k){
    vector<vector<int>> dp(n+1 , vector<int>(k + 1, 0)); //n번 물건까지 k무게만큼 고려했을 때 최대 가치합
    
    for(int i = 1; i <= n; i++){ // 물건 번호 
        for(int j = 1; j <= k; j++){ // 무게 
            dp[i][j] = max(dp[i][j-1], dp[i - 1][j]);
            if(j - thing[i].first >= 0){
                dp[i][j] = max(dp[i][j], thing[i].second + dp[i - 1][j - thing[i].first]);
            }
        }
    }
    
    return dp[n][k];
}

int main()
{
    int n, k;
    cin >> n >> k;
    
    vector<pair<int,int>> thing (n + 1, {0,0}); // {w, v} 무게, 가치 
    for(int i = 1; i <= n; i++){
        cin >> thing[i].first >> thing[i].second;
    }
    
    cout << solve(thing, n, k);
    
    return 0;
}