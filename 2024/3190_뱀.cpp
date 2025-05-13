#include<iostream>
#include<vector>
#include<map>
#include<deque>

using namespace std;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

int main() {
	int n, k; 
	cin >> n >> k;
	
	vector<vector<int>> board(n, vector<int>(n));

	for (int i = 0; i < k; i++) {
		int x, y; cin >> x >> y;
		board[x - 1][y - 1] = 2;
	}

	int L; cin >> L;

	map<int, char> time_direction;

	for (int i = 0; i < L; i++) {
		int t;
		char d;
		cin >> t >> d;
		time_direction[t] = d;
	}
	
	deque<pair<int, int>> snake;
	snake.push_front({ 0,0 });
	board[0][0] = 1;

	int t = 0, head = 0;
	while (true) {
		t++;

		int nx = snake.front().first + dx[head];
		int ny = snake.front().second + dy[head];

		if (nx < 0 || nx >= n || ny < 0 || ny >= n || board[nx][ny] == 1) {
			break;
		}

		if (board[nx][ny] != 2) {
			board[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}

		snake.push_front({ nx,ny });
		board[nx][ny] = 1;

		if (time_direction[t] == 'L') head = (head + 1) % 4;
		if (time_direction[t] == 'D') head = (head + 3) % 4;
	}

	cout << t;

	return 0;
}