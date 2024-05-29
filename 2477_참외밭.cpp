#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;

	int bBox = 1, sBox = 1;
	vector<int> check(5, 0);
	vector<pair<int, int>> v(7);

	for (int i = 0; i < 6; i++) {
		cin >> v[i].first >> v[i].second;
		check[v[i].first]++;
	}

	for (int i = 0; i < 6; i++) {
		if (check[v[i].first] == 1) {
			bBox *= v[i].second;
		}
		if (v[i].first == v[(i + 2) % 6].first) {
			sBox *= v[(i + 1) % 6].second;
		}
	}

	cout << n * (bBox - sBox);
}