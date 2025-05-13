#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve(vector<pair<int, int>>& field, vector<int>& dir) {
	int sbox = 1, bbox = 1;
	
	for (int i = 0; i < 6; i++) {
		if (dir[field[i].first] == 1) {
			bbox *= field[i].second;
		}
		if (field[i].first == field[(i + 2) % 6].first) {
			sbox *= field[(i + 1) % 6].second;
		}
	}
	return bbox - sbox;
}

int main() {
	int n;
	cin >> n;
	
	vector<pair<int,int>> field(6);
	vector<int> direction(5, 0);

	for (int i = 0; i < 6; i++) {
		cin >> field[i].first >> field[i].second;
		direction[field[i].first]++;
	}

	cout << n * solve(field, direction);

	return 0;
}