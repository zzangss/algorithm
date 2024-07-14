#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n; cin >> n;

	vector<int> a(n);
	vector<int> dp(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	dp[0] = 1;
	int max = 1;
	for (int i = 1; i < n; i++) {
		dp[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (a[j] > a[i] && dp[i] < dp[j] + 1) {
				dp[i] =dp[j] + 1;
			}
		}
		if (max < dp[i]) max = dp[i];
	}

	cout << max;

}