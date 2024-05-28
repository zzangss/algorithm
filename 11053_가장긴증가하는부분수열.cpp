#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> v(n + 1, 0);
	vector<int> check(n + 1, 1);
	
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	int max = 0;
	for (int i = 1; i <= n; i++) {
		check[i] = 1;
		for (int j = i - 1; j >= 1; j--) {
			if (v[i] > v[j] && check[j] >= check[i]) {
				check[i] = check[j] + 1;
			}
		}
		if (max < check[i]) max = check[i];
	}

	cout << max;
}