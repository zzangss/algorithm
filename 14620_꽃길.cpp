#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 3000

int n = 0;
int dx[4] = { 1,-1, 0, 0 };
int dy[4] = { 0,0, 1, -1 };
int minimum = MAX;

using namespace std;

bool check(vector<vector<int>>& visited, int x, int y) {
	if (visited[x][y] == 1) {
		return false;
	}
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		if (tx < 0 || tx >= n || ty < 0 || ty >= n) {
			return false;
		}
		if (visited[tx][ty] == 1) {
			return false;
		}
	}
	return true;
}

int makeSum(const vector<vector<int>>& flower_bed, int x, int y) {
	int sum = flower_bed[x][y];
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		sum += flower_bed[tx][ty];
	}
	return sum;
}

void checkVisited(vector<vector<int>>& visited,  int x, int y, int num) {
	visited[x][y] = num;
	for (int i = 0; i < 4; i++) {
		int tx = x + dx[i];
		int ty = y + dy[i];
		visited[tx][ty] = num;
	}
}

void calCost(const vector<vector<int>>& flower_bed, vector<vector<int>>& visited, int sum, int depth) {
	if (depth == 3) {
		minimum = min(minimum, sum);
		return;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (check(visited, i, j)) {
				int temp = makeSum(flower_bed, i, j);
				checkVisited(visited, i, j, 1);
				calCost(flower_bed, visited, sum + temp, depth + 1);
				checkVisited(visited, i, j, 0);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;

	vector<int> v(n, 0);
	vector<vector<int>> flower_bed(n, v);
	vector<vector<int>> visited(n, v);
	
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> flower_bed[i][k];
		}
	}

	calCost(flower_bed, visited, 0, 0);

	cout << minimum;

}