#include<iostream>
#include<vector>
#define MIN -10000001

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> dp(n + 1, 0);

	int max = MIN;
	for (int i = 1; i <= n; i++) {
		int temp;
		cin >> temp;
		if (dp[i - 1] + temp >= 0) {
			dp[i] = dp[i - 1] + temp;
		}
		else {
			dp[i] = temp;
		}
		if (max < dp[i]) {
			max = dp[i];
		}
		if (dp[i] < 0) dp[i] = 0;
	}

	cout << max;
}