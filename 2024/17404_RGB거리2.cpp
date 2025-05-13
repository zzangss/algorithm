#include<iostream>
#include<vector>
#define MAX 1000001

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	vector<int> v(3, 0);
	vector<vector<int>> house(n, v);
	vector<vector<int>> dp(n, v);

	for (int i = 0; i < n; i++) {
		cin >> house[i][0] >> house[i][1] >> house[i][2];
	}

	int result = MAX;
	for (int s = 0; s < 3; s++) {
		for (int check = 0; check < 3; check++) {
			if (check == s) dp[0][s] = house[0][s];
			else dp[0][check] = 1001;
		} //현재 확인하려는 색깔을 제외한 색깔은 MAX값을 주어 경우의 수에서 제외시킨다.
		for (int i = 1; i < n; i++) {
			dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + house[i][0];
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + house[i][1];
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + house[i][2];
		}
		for (int i = 0; i < 3; i++) { //1번집 색과 n번집 색이 같은 경우는 세지 않는다.
			if (i == s) continue;
			result = min(result, dp[n - 1][i]);
		}
	}

	cout << result;

	return 0;
}