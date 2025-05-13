#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

vector<int>v(10001);

int main() {
	int n;
	cin >> n;
	cin >> v[1];

	for (int i = 2; i <= n; i++) {
		cin >> v[i];
		for (int j = 1; j < i; j++) {
			v[i] = max(v[i], v[j] + v[i - j]);
		}
	}

	cout << v[n];
}