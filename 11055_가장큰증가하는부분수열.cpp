#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	vector<int> arr(n, 0);
	vector<int> dp(n);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	dp[0] = arr[0];
	int max = dp[0];

	for (int i = 1; i < n; i++) {
		dp[i] = arr[i];
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i]) {
				dp[i] = arr[i] + dp[j];
			}
		}
		if (max < dp[i]) max = dp[i];
	}

	cout << max;
	
}