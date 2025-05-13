#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	vector<int> v(500, 0);
	vector<vector<int>> triangle(500, v);
	vector<vector<int>> dp(500, v);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j];
		}
	}


	dp[0][0] = triangle[0][0];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) dp[i][j] = triangle[i][j] + dp[i - 1][j];
			else if (j == i) dp[i][j] = triangle[i][j] + dp[i - 1][j - 1];
			else {
				dp[i][j] = triangle[i][j] + max(dp[i - 1][j - 1], dp[i - 1][j]);
			}
		}
	}

	int max = 0;

	for (int i = 0; i < n; i++) {
		if (max < dp[n - 1][i]) {
			max = dp[n - 1][i];
		}
	}

	cout << max;
}