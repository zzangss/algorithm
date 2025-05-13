#include<iostream>
#include<vector>
#define MOD 1000000000

using namespace std;

int main() {
	int n;
	cin >> n;

	int dp[101][11];

	dp[1][0] = 0;
	for (int i = 1; i <= 9; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int k = 0; k <= 9; k++) {
			if (k == 0) {
				dp[i][k] = dp[i - 1][1] % MOD;
			}
			else if (k == 9) {
				dp[i][k] = dp[i - 1][8] % MOD;
			}
			else {
				dp[i][k] = (dp[i - 1][k + 1] + dp[i - 1][k - 1]) % MOD;
			}
		}
	}
	
	int result = 0;
	for (int i = 0; i <= 9; i++) {
		result += dp[n][i];
		result %= MOD;
	}

	cout << result;
}