#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;

	vector<int> v(n);
	vector<int> a(2, 0);
	vector<vector<int>>dp(n, a);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	dp[0][0] = dp[0][1] = v[0];
	int result = v[0];

	for (int i = 1; i < n; i++) {
		dp[i][0] = dp[i][1] = v[i];
		
		dp[i][0] = max(dp[i-1][0] + v[i], v[i]);
		dp[i][1] = max(dp[i-1][0], dp[i-1][1] + v[i]);
		
		result = max(result, max(dp[i][0], dp[i][1]));
	}
	
	cout << result;
}