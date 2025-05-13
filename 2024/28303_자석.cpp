#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;

	vector<int> v(n, 0);
	int result = -2e18;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	for (int p = 0; p < 2; p++) {
		int minJ = v[0];
		for (int i = 1; i < n; i++) {
			result = max(result, v[i] - i * k - minJ);
			minJ = min(minJ, v[i] - i * k);
		}
		reverse(v.begin(), v.end());
	}

	cout << result;

}