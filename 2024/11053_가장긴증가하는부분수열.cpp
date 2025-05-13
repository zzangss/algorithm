#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	vector<int> A(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> A[i];
	}

	vector<int> dp(n + 1, 1);
	int result = 0;

	for (int i = 1; i <= n; i++) {
		for(int j = i-1; j>= 1; j--){
			if (A[i] > A[j] && dp[j] >= dp[i]) {
				// ���� ���Һ��� A[j]�� ũ�Ⱑ �۰�, 
				// j��°���� ������ ���̰� ���� ������ ������ ũ�ų� ������
				dp[i] = dp[j] + 1;
			}
		}
		result = max(result, dp[i]);
	}

	cout << result;
	return 0;
}