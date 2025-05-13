#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, m; cin >> n >> m;

	vector<int> v(m, 0);
	vector<vector<int>> a(n, v);
	vector<vector<int>> b(n, v);

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> a[i][k];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> b[i][k];
			cout << a[i][k] + b[i][k] << " ";
		}
		cout << endl;
	}


}