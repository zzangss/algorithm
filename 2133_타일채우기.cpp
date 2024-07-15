#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	vector<int> dp(n + 1, 0);

	dp[0] = 1;
	dp[2] = 3;

	for (int i = 4; i <= n; i += 2) {
		dp[i] = dp[i - 2] * dp[2];
		for (int k = i - 4; k >= 0; k -= 2) {
			dp[i] += dp[k] * 2; //특별한 모양의 경우
		}
		
	}

	cout << dp[n];
	return 0;
}