#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve(vector<pair<int, int>> v) {

	int result = 1;
	vector<int> dp(v.size(), 1);

	int temp = 0;
	for (int i = 1; i < v.size(); i++) {
		if (v[i].second < v[temp].second) {
			temp = i;
			result++;
		}
	}

	return result;
}

int main() {
	int t; cin >> t;

	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		vector<pair<int,int>> v(n);
		for (int k = 0; k < n; k++) {
			cin >> v[k].first >> v[k].second;
		}
		sort(v.begin(), v.end());
		cout << solve(v) << endl;
	}

	return 0;
}