//시간초과 코드

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector<int> numCard, checkCard;
vector<int> visited;
int n;

int around_search(int target, int now) {
	if (now > n - 1 || now < 0) return 0;
	if (visited[now] == 1) return 0;

	visited[now] = 1;

	if (target != numCard[now]) return 0;
	else {
		return around_search(target, now - 1) + around_search(target, now + 1) + 1;
	}
}

int binary_search(int target, int s, int e) {
	if (s > e) return 0;

	int m = (s + e) / 2;
	if (target == numCard[m]) {
		visited.clear();
		visited.resize(n, 0);
		return around_search(target, m);
	}
	else if (target > numCard[m]) {
		return binary_search(target, m + 1, e);
	}
	else if (target < numCard[m]) {
		return binary_search(target, s, m - 1);
	}
}

int main() {
	cin >> n;
	numCard.resize(n, 0);

	for (int i = 0; i < n; i++) {
		cin >> numCard[i];
	}
	sort(numCard.begin(), numCard.end());

	int m; cin >> m;

	for (int i = 0; i < m; i++) {
		int target;

		cin >> target;
		cout << binary_search(target, 0, n - 1) << ' ';
	}
}
