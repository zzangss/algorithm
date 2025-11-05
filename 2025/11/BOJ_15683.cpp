// BOJ 15683 - 감시

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dir_n[4] = { -1, 0, 1, 0 }; // 상, 우, 하, 좌
int dir_m[4] = { 0, 1, 0, -1 };

void fixDir(vector<vector<int>>& grid, int dir, int x, int y, int n, int m) {
	// dir : 0(상), 1(우), 2(하), 3(좌) 방향으로 감시된 구역 표시

	grid[x][y] = -1; // CCTV 위치도 감시 처리
	while (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != 6) {
		if (grid[x][y] == 0) {
			grid[x][y] = -1; // 감시 처리
		}
		x += dir_n[dir];
		y += dir_m[dir];
	}
}

int searchEmpty(const vector<vector<int>>& grid, int n, int m) {
	// 감시되지 않은 구역(0)의 개수 세기

	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == 0) {
				sum++;
			}
		}
	}
	return sum;
}

int dfs(vector<pair<int, pair<int, int>>>& cctv_list, int idx, vector<vector<int>>& grid, int n, int m) {
	//dfs를 이용해 cctv 방향 조합 완전 탐색 

	if (idx == cctv_list.size()) {
		return searchEmpty(grid, n, m);
	}

	pair<int, pair<int, int>> cctv = cctv_list[idx];
	int x = cctv.second.first;
	int y = cctv.second.second;
	int min_blind_spot = 1e9;

	// 현재 그리드 상태 저장
	// CCTV 방향 고정
	switch (cctv.first) {
	case 1:
		for (int i = 0; i < 4; i++) {
			vector<vector<int>> temp_grid = grid;
			fixDir(temp_grid, i, x, y, n, m);
			min_blind_spot = min(min_blind_spot, dfs(cctv_list, idx + 1, temp_grid, n, m));
		}
		break;
	case 2:
		for (int i = 0; i < 2; i++) {
			vector<vector<int>> temp_grid = grid;
			fixDir(temp_grid, i, x, y, n, m);
			fixDir(temp_grid, i + 2, x, y, n, m);
			min_blind_spot = min(min_blind_spot, dfs(cctv_list, idx + 1, temp_grid, n, m));
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++) {
			vector<vector<int>> temp_grid = grid;
			fixDir(temp_grid, i, x, y, n, m);
			fixDir(temp_grid, (i + 1) % 4, x, y, n, m);
			min_blind_spot = min(min_blind_spot, dfs(cctv_list, idx + 1, temp_grid, n, m));
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++) {
			vector<vector<int>> temp_grid = grid;
			fixDir(temp_grid, (i) % 4, x, y, n, m);
			fixDir(temp_grid, (i + 1) % 4, x, y, n, m);
			fixDir(temp_grid, (i + 2) % 4, x, y, n, m);
			min_blind_spot = min(min_blind_spot, dfs(cctv_list, idx + 1, temp_grid, n, m));
		}
		break;
	case 5:
		vector<vector<int>> temp_grid = grid;
		for (int i = 0; i < 4; i++) {
			fixDir(temp_grid, i, x, y, n, m);
		}
		min_blind_spot = min(min_blind_spot, dfs(cctv_list, idx + 1, temp_grid, n, m));
		break;
	}

	return min_blind_spot;
}

int solve(vector<vector<int>>& grid, int n, int m) {
	// CCTV 위치 및 종류 저장

	vector<pair<int, pair<int, int>>> cctv_list;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] >= 1 && grid[i][j] <= 5) {
				cctv_list.push_back({ grid[i][j], {i, j} });
			}
		}
	}

	return dfs(cctv_list, 0, grid, n, m);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	cin >> n >> m;

	vector<vector<int>> grid(n, vector<int>(m, 0));

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> grid[i][j];
		}
	}

	cout << solve(grid, n, m) << "\n";

	return 0;
}