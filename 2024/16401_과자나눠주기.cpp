#include<iostream>
#include<vector>
#include<algorithm>

#define MAX_LEN 1000000000

using namespace std;

bool check(vector<int>& snack, int kid, int m) {
	int num_of_snack = 0;
	if (m == 0) {
		return false;
	}
	for (int i = 0; i < snack.size(); i++) {
		num_of_snack += snack[i] / m;
	}
	if (num_of_snack >= kid) {
		return true;
	}
	else {
		return false;
	}
}

int solve(vector<int>& snack, int kid) {
	int s = 1, e = MAX_LEN, m;
	int result = 0;
	while (s <= e) {
		m = (s + e) / 2;
		if (check(snack, kid, m)) {
			result = m;
			s = m + 1;
		}
		else {
			e = m - 1;
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int m, n; cin >> m >> n;
	
	vector<int> snack(n);
	for (int i = 0; i < n; i++) {
		cin >> snack[i];
	}
	sort(snack.begin(), snack.end());

	//출력
	cout << solve(snack, m);
}