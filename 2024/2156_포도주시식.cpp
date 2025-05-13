#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;
	
	vector<int> value(n, 0);
	vector<int> dp(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> value[i];
	}

	dp[0] = value[0];
	dp[1] = value[1] + value[0];
	dp[2] = max(dp[1],max(value[0] + value[2], value[1] + value[2]));

	for (int i = 3; i < n; i++) {
		dp[i] = max(dp[i - 3] + value[i - 1] + value[i], max(dp[i-1], dp[i - 2] + value[i]));
	}

	cout << dp[n-1];
}