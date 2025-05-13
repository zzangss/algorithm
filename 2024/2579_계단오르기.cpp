#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// 입력
	int stair_num; cin >> stair_num;

	vector<int> stair(stair_num+1, 0);

	for (int i = 1; i <= stair_num; i++) {
		cin >> stair[i];
	}

	// 연산
	vector<int> dp(stair_num + 1, 0); // i번째 계단에 올라가는 최고 점수 저장

	dp[1] = stair[1];
	dp[2] = dp[1] + stair[2];
	for (int i = 3; i <= stair_num; i++) {
		dp[i] = max(dp[i - 3] + stair[i - 1] + stair[i], dp[i - 2] + stair[i]);
		// 마지막 계단을 꼭 밟아야 한다. 그래서 dp[i]의 경우의 수가 줄어든다.
	}
	
	// 출력
	cout << dp[stair_num];
	return 0;
}