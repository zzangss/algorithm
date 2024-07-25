#include<iostream>
#include<string>
#include<vector>

using namespace std;

int n, m;
vector<vector<int>> arr;
vector<vector<int>> check;
int dirX[4] = {0,1,0,-1};
int dirY[4] = {1,0,-1,0};
int result;

void dfs(int nx, int ny, int d, int sum) {
	if (d == 4) {
		result = max(result, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int next_x = nx + dirX[i];
		int next_y = ny + dirY[i];

		if (next_x >= 0 && next_x <= n - 1) {
			if (next_y >= 0 && next_y <= m - 1) {
				if (check[next_x][next_y] == 0) {
					check[next_x][next_y] = 1;
					dfs(next_x, next_y, d + 1, sum + arr[next_x][next_y]);
					check[next_x][next_y] = 0;
				}
			}
		}
	}

	//た
	if (nx + 1 < n && ny + 1 < m && ny - 1 >= 0) {
		result = max(result, arr[nx][ny] + arr[nx + 1][ny] + arr[nx][ny + 1] + arr[nx][ny - 1]);
	}
	//っ
	if (nx - 1 >= 0 && ny + 1 < m && ny - 1 >= 0) {
		result = max(result, arr[nx][ny] + arr[nx - 1][ny] + arr[nx][ny + 1] + arr[nx][ny - 1]);
	}
	//ぬ
	if (nx - 1 >= 0 && nx + 1 < n && ny + 1 < m) {
		result = max(result, arr[nx][ny] + arr[nx - 1][ny] + arr[nx + 1][ny] + arr[nx][ny + 1]);
	}
	//で
	if (nx - 1 >= 0 && nx + 1 < n && ny - 1 >= 0) {
		result = max(result, arr[nx][ny] + arr[nx - 1][ny] + arr[nx + 1][ny] + arr[nx][ny - 1]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> m;

	vector<int> v(m, 0);
	arr.resize(n, v);
	check.resize(n, v);

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			cin >> arr[i][k];
		}
	}

	result = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < m; k++) {
			check[i][k] = 1;
			dfs(i, k, 1, arr[i][k]);
			check[i][k] = 0;
		}
	}

	cout << result;
}