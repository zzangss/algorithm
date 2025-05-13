#include<iostream>
#include<vector>
#define BOARD_SIZE 19

using namespace std;

// 보드와 이동방향을 전역변수로 선언
vector<vector<int>> board(BOARD_SIZE + 1, vector<int>(BOARD_SIZE + 1));
int x[4] = { -1,0,1,1 };
int y[4] = { 1,1,1,0 }; // (오른쪽위, 오른쪽, 오른쪽 아래, 아래) 이동 인덱스 저장

bool isInBoard(int x, int y) {
	// x,y가 보드 위의 값인지 확인
	if (x >= 1 && x <= BOARD_SIZE && y >= 1 && y <= BOARD_SIZE) {
		return true;
	}
	else {
		return false;
	}
}

int backtracking(int nx, int ny, int dir, int d) {
	int next_x = nx + x[dir];
	int next_y = ny + y[dir];

	if (d == 5) {
		// 1 - 1. d == 5 인데 다음이 있는 경우 -> 0
		if (isInBoard(next_x, next_y) && board[nx][ny] == board[next_x][next_y]) {
			return 0;
		}
		// 1 - 2. 다음이 없는 경우 -> 돌 색깔 리턴
		else {
			return board[nx][ny];
		}
	}

	// 다음 좌표가 보드를 벗어남
	// 혹은 다음 좌표가 보드를 벗어나지 않음 & 하지만 수가 다름
	if (!isInBoard(next_x, next_y) || isInBoard(next_x, next_y) && board[nx][ny] != board[next_x][next_y]) {
		return 0;
	}

	return backtracking(next_x, next_y, dir, d + 1);
}

int main() {
	for (int i = 1; i <= BOARD_SIZE; i++) {
		for (int k = 1; k <= BOARD_SIZE; k++) {
			cin >> board[i][k];
		}
	}

	for (int i = 1; i <= BOARD_SIZE; i++) {
		for (int k = 1; k <= BOARD_SIZE; k++) {
			if (board[i][k] > 0) {
				for (int j = 0; j < 4; j++) {
					int tx = i - x[j];
					int ty = k - y[j];
					if (isInBoard(tx, ty) && board[i][k] == board[tx][ty]) {
						// 오른쪽 위 대각선을 살표보는 경우, 왼쪽 아래에 돌이 있을 수도 있다.
						// 그래서 현재 돌의 앞쪽(방향은 같음)에 같은 색 돌이 있으면 백트래킹을 건너뛴다.
						// 이렇게 하면 다른 경우에서(오른쪽, 오른쪽 아래, 아래) 중복 계산도 방지할 수 있다.
						continue;
					}
					int result = backtracking(i, k, j, 1);
					if (result > 0) {
						cout << result << "\n";
						cout << i << " " << k;
						return 0;
					}
				}
			}
		}
	}

	cout << 0;
	return 0;

}