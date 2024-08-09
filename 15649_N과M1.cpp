#include<iostream>

using namespace std;

int arr[9];
bool visited[9] = { false , };

void dfs(int n, int m, int d) {
	if (d == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			arr[d] = i;
			dfs(n, m, d + 1);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m; cin >> n >> m;

	dfs(n, m, 0);

	return 0;
}