#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve(const vector<int>& atm) {
	int result = 0, sum = 0;

	for (int i = 0; i < atm.size(); i++) {
		sum += atm[i];
		result += sum;
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;

	vector<int> atm(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> atm[i];
	}

	sort(atm.begin(), atm.end());
	
	cout << solve(atm);

	return 0;
}