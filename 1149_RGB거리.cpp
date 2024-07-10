#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	vector<int> v(3);
	vector<vector<int>> arr(n, v);

	int r, g, b;
	cin >> r >> g >> b;
	arr[0][0] = r;
	arr[0][1] = g;
	arr[0][2] = b;
	for (int i = 1; i < n; i++) {
		cin >> r >> g >> b;
		arr[i][0] = min(arr[i - 1][1], arr[i - 1][2]) + r;
		arr[i][1] = min(arr[i - 1][0], arr[i - 1][2]) + g;
		arr[i][2] = min(arr[i - 1][1], arr[i - 1][0]) + b;
	}

	cout << min(arr[n-1][2], min(arr[n-1][0], arr[n-1][1]));
}