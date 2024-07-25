#include<iostream>
#include<string>
#include<vector>

using namespace std;

int n, m;
vector<bool> remo;

bool check(int i) {
	if (i == 0) {
		if (remo[0]) return true;
		else return false;
	}
	while (i) {
		if (!remo[i % 10]) return false;
		i /= 10;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> m;

	remo.resize(10, true); 

	for (int i = 0; i < m; i++) {
		int temp; cin >> temp;
		remo[temp] = false;
	}

	int result = abs(n - 100);

	for (int i = 0; i <= 1000000; i++) {
		int temp;
		if (check(i)) {
			temp = to_string(i).length();
			temp += abs(n - i);
			result = min(result, temp);
		}
	}

	cout << result;
}