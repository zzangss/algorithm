#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;

	vector<int> v(n);
	vector<int> temp(m);
	int check;

	for (int i = 0; i < n; i++) {
		v[i] = i + 1;
	}
	
	do {
		check = true;
		for (int i = 0; i < m; i++) {
			if (temp[i] != v[i]) {
				check = false;
				break;
			}
		}
		if (check) {
			continue;
		}
		for (int i = 0; i < m; i++) {
			cout << v[i] << " ";
			temp[i] = v[i];
		}
		cout << "\n";
	} while (next_permutation(v.begin(), v.end()));

	return 0;
}