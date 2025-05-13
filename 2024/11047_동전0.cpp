#include<iostream>
#include<vector>

using namespace std;

int countCoin(const vector<int>& kind_of_coin, int n, int money) {
	int result = 0;

	while (n--) {
		result += money / kind_of_coin[n];
		money %= kind_of_coin[n];
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//�Է�
	int n, money;
	cin >> n >> money;

	vector<int> kind_of_coin(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> kind_of_coin[i];
	}

	// ���� �� ���
	cout << countCoin(kind_of_coin, n, money);

	return 0;
}