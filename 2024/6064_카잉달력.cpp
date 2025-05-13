#include<iostream>
#include<string>
#include<vector>

using namespace std;

int GCD(int a, int b) {
	int gcd = a * b;
	if (a < b) {
		int temp = a;
		a = b;
		b = temp;
	}

	int n;
	while (b != 0) {
		n = a % b;
		a = b;
		b = n;
	}
	return gcd/a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t; cin >> t;

	for (int i = 0; i < t; i++) {
		int n, m, x, y;
		bool check = false;
		cin >> n >> m >> x >> y;
		int gcd = GCD(n, m);
		if (x == 1 && y == 1) {
			cout << 1 << endl;
			continue;
		}
		if (n == x && m == y) {
			cout << gcd << endl;
			continue;
		}
		if (x == n) x = 0;
		if (y == m) y = 0;
		for (int k = 1; k <= gcd; k++) {
			if (k % n == x && k % m == y) {
				cout << k <<endl;
				check = true;
			}
		}
		if (!check) cout << -1 << endl;
	}

}