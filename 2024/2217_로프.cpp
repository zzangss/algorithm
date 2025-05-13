#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int>v(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), greater<>());

	long long result = 0;

	for (int i = 1; i <= n; i++)
	{
		int now;
		now = i * v[i - 1];
		result = max(result, (long long)i * v[i - 1]);
	}

	cout << result;
}