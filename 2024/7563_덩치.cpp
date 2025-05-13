#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<pair<int, int>> v;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b });
	}

	for (int i = 0; i < n; i++) {
		int result = 1;
		for (int k = 0; k < n; k++) {
			if (v[i].first < v[k].first && v[i].second < v[k].second) {
				result++;
			}
		}
		cout << result << " ";
	}
}