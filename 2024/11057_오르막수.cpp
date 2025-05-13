#include<iostream>
#include<vector>
#define MOD 10007

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	vector<int> v(10, 1);
	vector<vector<int>> arr(n, v);
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < 10; j++) {
			arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % MOD;
		}
	}
	int result = 0;

	for (int i = 0; i < 10; i++) {
		result += arr[n - 1][i];
	}

	cout << result % MOD;
}