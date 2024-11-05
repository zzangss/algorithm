#include<iostream>
#include<vector>
#define BOARD_SIZE 19

using namespace std;

// ����� �̵������� ���������� ����
vector<vector<int>> board(BOARD_SIZE + 1, vector<int>(BOARD_SIZE + 1));
int x[4] = { -1,0,1,1 };
int y[4] = { 1,1,1,0 }; // (��������, ������, ������ �Ʒ�, �Ʒ�) �̵� �ε��� ����

bool isInBoard(int x, int y) {
	// x,y�� ���� ���� ������ Ȯ��
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
		// 1 - 1. d == 5 �ε� ������ �ִ� ��� -> 0
		if (isInBoard(next_x, next_y) && board[nx][ny] == board[next_x][next_y]) {
			return 0;
		}
		// 1 - 2. ������ ���� ��� -> �� ���� ����
		else {
			return board[nx][ny];
		}
	}

	// ���� ��ǥ�� ���带 ���
	// Ȥ�� ���� ��ǥ�� ���带 ����� ���� & ������ ���� �ٸ�
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
						// ������ �� �밢���� ��ǥ���� ���, ���� �Ʒ��� ���� ���� ���� �ִ�.
						// �׷��� ���� ���� ����(������ ����)�� ���� �� ���� ������ ��Ʈ��ŷ�� �ǳʶڴ�.
						// �̷��� �ϸ� �ٸ� ��쿡��(������, ������ �Ʒ�, �Ʒ�) �ߺ� ��굵 ������ �� �ִ�.
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