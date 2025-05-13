#include<iostream>
#include<vector>

using namespace std;

vector<bool> visited;
vector<vector<int>> w;
int ans = 1e8;

void backtracking(int n, int d, int now_city, int cost) {
	if (cost >= ans) {
		return;
	}
	if (d == n) {
		if (w[now_city][0] != 0) {
			ans = min(ans, w[now_city][0] + cost);
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (w[now_city][i] && !visited[i]) {
			visited[i] = true;
			backtracking(n, d + 1, i, cost + w[now_city][i]);
			visited[i] = false;
		}
	}
}

int solution(const int n, const vector<vector<int>>& w) {
	visited.assign(n, false);

	visited[0] = true;
	backtracking(n, 1, 0, 0);

	return ans;
}

int main() {
	int n;
	cin >> n;

	w.assign(n, vector<int>(n,0));

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> w[i][k];
		}
	}

	cout << solution(n, w);

	return 0;
}