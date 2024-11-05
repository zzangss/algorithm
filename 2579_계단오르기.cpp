#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	// �Է�
	int stair_num; cin >> stair_num;

	vector<int> stair(stair_num+1, 0);

	for (int i = 1; i <= stair_num; i++) {
		cin >> stair[i];
	}

	// ����
	vector<int> dp(stair_num + 1, 0); // i��° ��ܿ� �ö󰡴� �ְ� ���� ����

	dp[1] = stair[1];
	dp[2] = dp[1] + stair[2];
	for (int i = 3; i <= stair_num; i++) {
		dp[i] = max(dp[i - 3] + stair[i - 1] + stair[i], dp[i - 2] + stair[i]);
		// ������ ����� �� ��ƾ� �Ѵ�. �׷��� dp[i]�� ����� ���� �پ���.
	}
	
	// ���
	cout << dp[stair_num];
	return 0;
}