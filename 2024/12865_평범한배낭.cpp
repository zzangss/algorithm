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
	// (n��°������ ������ k ���� ���Ϸ� ���� ��)�� ��ġ �ִ� ����

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (j - items[i].first >= 0) {
				dp[i][j] = max(items[i].second + dp[i - 1][j - items[i].first], dp[i - 1][j]);
				// ���� ���� Ȯ������ i��° ������ ���԰� j���� ũ�ų� ��������
				// i��° ������ ���濡 ���� �� �ִ� ���ɼ��� �����.
				// ���� �̶� �� ���� ��� �� �� ū ��ġ�� ������ ��츦 dp�� �����Ѵ�.
				// 1. i��° ������ ��ġ + (i-1)��°������ ������ (j - (i��° ������ ����)) ���Ϸ� �������� ��ġ �ִ�
				// 2. (i-1)��° ������ ������ j���� ���Ϸ� ���� ���� ��ġ �ִ�
			}
			else {
				dp[i][j] = dp[i - 1][j];
				// �賶�� i��° ������ ���� �� �����Ƿ� ���� ���Ǳ����� �ִ��� �־��ش�.
			}
		}
	}

	cout << dp[n][k];

	return 0;
}