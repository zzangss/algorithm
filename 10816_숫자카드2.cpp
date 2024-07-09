#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, x;
	cin >> n;
	
	vector<int> card(n);

	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}

	sort(card.begin(), card.end());

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		cout << upper_bound(card.begin(), card.end(), x) - lower_bound(card.begin(), card.end(), x) << " ";
	}

	return 0;
}
