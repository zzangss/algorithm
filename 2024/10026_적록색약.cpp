#include<iostream>
#include<vector>
#include<memory.h>
#include<string>

using namespace std;

int n, cnt = 0;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1}; //상하좌우 움직이기 위한 배열
vector<string>rgb; //띄어쓰기 없이 받기 때문에 string 자료형 사용
vector<vector <int>> check; // 2차원 벡터

bool range(int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n) {
		return true;
	}
	else {
		return false;
	}
}

void DFS(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (range(nx, ny) && !check[nx][ny] && rgb[x][y] == rgb[nx][ny]) {
			check[nx][ny] = true;
			DFS(nx, ny);
		}
	}
}

void rTog() {
	for (int i = 0; i < n; i++) {
		string temp = "";
		for (int j = 0; j < n; j++) {
			if (rgb[i][j] == 'R') {
				temp += 'G';
			}
			else {
				temp += rgb[i][j];
			}
		}
		rgb[i] = temp;
	}
}

int solve() {
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (!check[i][k]) {
				check[i][k] = true;
				DFS(i, k);
				result++;
			}
		}
	}
	return result;
}

int main() {
	cin >> n;

	rgb.resize(n);
	check.resize(n,vector<int>(n,0));	

	for (int i = 0; i < n; i++) {
		cin >> rgb[i];
	}

	// 일반적인 경우
	cout << solve() << " ";

	// 적록색약인 경우
	check.assign(n, vector<int>(n,false)); //check의 값을 다시 0으로 
	rTog();
	cout << solve();
	
}