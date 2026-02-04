// boj 2448 별 찍기 - 11 (40m)

#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

vector<vector<bool>> board;
vector<int> width;

void calWidth(int n) {
    width[0] = 5;
    for (int i = 1; i <= n; i++) {
        width[i] = width[i - 1] * 2 + 1;
    }
}

int calK(int n) {
    int k = 0;
    while (n > 3) {
        n /= 2;
        k++;
    }
    return k;
}
void printBoard(int n) {
	int k = calK(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < width[k]; j++) {
            if (board[i][j]) {
                cout << '*';
            }
            else {
                cout << ' ';
            }
        }
        cout << "\n";
    }
}


void solve(int n, int row, int col) {
    if (n == 3) {
        board[row][col] = board[row + 1][col - 1] = board[row + 1][col + 1] = true;
        for (int i = 0; i < 5; i++) {
            board[row + 2][col + i - 2] = true;
        }
        return;
    }

	int k = calK(n);
    solve(n / 2, row, col);
    solve(n / 2, row + n / 2, col - width[k - 1] / 2 - 1);
    solve(n / 2, row + n / 2, col + width[k - 1] / 2 + 1);
}

int main() {
    int n;
    cin >> n;


    width.assign(11, 0);
    calWidth(10);

    int k = calK(n);
    board.assign(n, vector<bool>(width[k], false));

    solve(n, 0, width[k] / 2);

    printBoard(n);
}