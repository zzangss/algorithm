#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int binary(vector<int>&card, int key,int s, int e) {
	//key값과 일치하는 값이 카드에 있으면 1 반환, 없으면 0 반환
	int m;
	while (s <= e) {
		m = (s + e) / 2;
		if (card[m] == key) {
			return 1;
		}
		else if (card[m] > key) {
			e = m - 1;
		}
		else {
			s = m + 1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	vector<int> card(n,0);

	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	sort(card.begin(), card.end());

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		cout << binary(card, num, 0, n - 1) << " ";
	}
}