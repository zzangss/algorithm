#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> v(1001,10000);

	cin >> v[1];
	for (int i = 2; i <= n; i++) {
		cin >> v[i];
		for (int j = 1; j <= i; j++) {
			v[i] = min(v[i], v[j] + v[i - j]);
		}
	}

	cout << v[n];
}