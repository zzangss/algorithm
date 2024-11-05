#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, k; cin >> n >> k;

	vector<pair<int, int>> items(n + 1, { 0,0 });

	for (int i = 1; i <= n; i++) {
		cin >> items[i].first >> items[i].second;
	}

	sort(items.begin(), items.end());

	vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0)); 
	// (n번째까지의 물건을 k 무게 이하로 넣은 것)의 가치 최댓값 저장

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j - items[i].first >= 0) {
				dp[i][j] = max(items[i].second + dp[i - 1][j - items[i].first], dp[i - 1][j]);
				// 만약 현재 확인중인 i번째 물건의 무게가 j보다 크거나 같아지면
				// i번째 물건을 가방에 넣을 수 있는 가능성이 생긴다.
				// 따라서 이때 두 가지 경우 중 더 큰 가치를 가지는 경우를 dp에 저장한다.
				// 1. i번째 물건의 가치 + (i-1)번째까지의 물건을 (j - (i번째 물건의 무게)) 이하로 넣은것의 가치 최댓값
				// 2. (i-1)번째 까지의 물건을 j무게 이하로 넣은 것의 가치 최댓값
			}
			else {
				dp[i][j] = dp[i - 1][j];
				// 배낭에 i번째 물건을 넣을 수 없으므로 이전 물건까지의 최댓값을 넣어준다.
			}
		}
	}

	cout << dp[n][k];

	return 0;
}