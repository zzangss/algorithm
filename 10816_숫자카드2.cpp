//시간초과 코드

#include<iostream>
#include<algorithm>
#include<map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m, x;
	cin >> n;
	
	map<int, int> card;

	for (int i = 0; i < n; i++) {
		cin >> x;
		card[x]++;
	}

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x;
		cout << card[x] << " ";
	}
}
