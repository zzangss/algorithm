#include<iostream>
#include<vector>
#define MAX 1000000009

using namespace std;

vector<long long> check(1000001, -1);

long long dP(int n) {
	if (n == 1) return 1;
	if (n == 2) return 2;
	if (n == 3) return 4;

	if (check[n] != -1) {
		return check[n];
	}
	check[n] = dP(n - 3)%MAX + dP(n - 2)%MAX + dP(n - 1)%MAX;
	return check[n];
}

int main() {
	int t; cin >> t;

	dP(1);

	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		cout << dP(n)%MAX << endl;
	}
}