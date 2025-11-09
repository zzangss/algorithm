// BOJ 2579 - 계단 오르기

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve(const vector<int>& stair, int n) {
    vector<int> dp(n + 1, 0);

    dp[1] = stair[1];
    dp[2] = dp[1] + stair[2];

    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i - 3] + stair[i - 1] + stair[i], dp[i - 2] + stair[i]);
    }

    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> stair(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> stair[i];
    }

    cout << solve(stair, n);
}