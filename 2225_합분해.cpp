#include<iostream>
#include<vector>
#define MAX 1000000000

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> v(k+1, 0);
	vector<vector<int>> arr(n+1, v);

	for (int i = 1; i <= k; i++) {
		arr[1][i] = i;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			arr[i][j] = (arr[i][j - 1] + arr[i - 1][j]) % MAX;
		}
	}

	cout << arr[n][k];
}