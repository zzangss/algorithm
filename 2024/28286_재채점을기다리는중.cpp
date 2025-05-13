#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, k;
vector<int> answer;
vector<int> check;
int result;

void DFS(int d, vector<int> v) {
	if (d > k) {
		return;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (answer[i] == v[i]) {
			cnt++;
		}
	}
	result = max(result, cnt);

	for (int i = 0; i < n; i++) {
		if (v[i] > 0) {
			vector<int> tmp;
			tmp.resize(n);
			tmp = v;
			for (int j = i; j < n - 1; j++) {
				tmp[j] = tmp[j + 1];
			}
			tmp[n - 1] = 0;
			DFS(d + 1, tmp);

			tmp = v;
			for (int j = (n - 1); j > i; j--) {
				tmp[j] = tmp[j - 1];
			}
			tmp[i] = 0;
			DFS(d + 1, tmp);
		}
	}
}

int main() {
	cin >> n >> k;
	answer.resize(n);
	check.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> answer[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> check[i];
	}

	DFS(0, check);

	cout << result;

	return 0;
}