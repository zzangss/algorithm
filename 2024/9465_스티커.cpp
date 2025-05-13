#include<iostream>
#include<vector>
#define MAX 100001

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	vector<int> v(MAX, 0);
	vector<vector<int>> dp(2, v);
	vector<vector<int>> value(2, v);

	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		
		for (int j = 0; j < 2; j++) {
			for (int k = 1; k <= t; k++) {
				cin >> value[j][k];
			}
		}

		dp[0][0] = dp[1][0] = 0;
		dp[0][1] = value[0][1];
		dp[1][1] = value[1][1];

		for (int j = 2; j <= t; j++) {
			dp[0][j] = max(dp[1][j - 1], dp[1][j - 2]) + value[0][j];
			dp[1][j] = max(dp[0][j - 1], dp[0][j - 2]) + value[1][j];
		}

		cout << max(dp[0][t], dp[1][t]) << endl;
	}

	return 0;
}