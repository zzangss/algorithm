#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(100001, 0);
	vector<vector<int>>d(3, v);

	d[0][1] = 1;
	d[1][1] = 1;
	d[2][1] = 1;

	for (int i = 2; i <= n; i++) {
		d[0][i] = (d[0][i - 1] + d[1][i - 1] + d[2][i - 1])%9901;
		d[1][i] = (d[0][i - 1] + d[2][i - 1])%9901;
		d[2][i] = (d[0][i - 1] + d[1][i - 1])%9901;
	}

	cout << (d[0][n] + d[1][n] + d[2][n]) % 9901;

	return 0;

}