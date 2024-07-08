#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

static int n;
static vector<long> v;
int binary_search(long num, int s, int e);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;

	v = vector<long>(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end());

	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		long num;
		cin >> num;
		cout << binary_search(num, 0, n - 1) << "\n";

	}

}

int binary_search(long num, int s, int e) {
	bool check = false;
	while (s <= e) {
		int m = (s + e) / 2;
		if (num == v[m]) {
			check = true;
			break;
		}
		else if (num > v[m]) {
			s = m + 1;
		}
		else {
			e = m - 1;
		}
	}

	if (check) {
		return 1;
	}
	else {
		return 0;
	}

}