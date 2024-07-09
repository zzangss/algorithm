//시간 초과 이유를 모르겠음.

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int n, m, x;
vector<int> card(n);

int lower_b(vector<int> card, int target) {
	int s = 0, e = n-1;
	int mid;

	while (e > s) {
		mid = (s + e) / 2;
		if (card[mid] >= target) e = mid;
		else s = mid + 1;
	}
	return e;
}

int upper_b(vector<int> card, int target) {
	int s = 0, e = n - 1;
	int mid;

	while (e > s) {
		mid = (s + e) / 2;
		if (card[mid] > target) e = mid;
		else s = mid + 1;
	}
	return e;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	card.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	sort(card.begin(), card.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		int u = upper_b(card, x);
		int l = lower_b(card, x);
		if (u == n - 1 && card[n - 1] == x) {
			u++;
		}
		cout << u - l << " ";
	}

	return 0;
}
