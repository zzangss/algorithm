#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

bool compare(string a, string b) {
	if (a.size() != b.size()) {
		return a.size() < b.size();
	}

	int sum1 = 0, sum2 = 0;
	for (int i = 0; i < a.size(); i++) {
		if ('0' <= a[i] && a[i] <= '9') {
			sum1 += a[i] - '0';
		}
		if ('0' <= b[i] && b[i] <= '9') {
			sum2 += b[i] - '0';
		}
	}

	if (sum1 != sum2) {
		return sum1 < sum2;
	}

	for (int i = 0; i < a.size(); i++) {
		if (a[i] != b[i]) {
			return a[i] < b[i];
		}
	}
}

int main() {
	int n; cin >> n;

	vector<string> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << v[i] << endl;
	}
}