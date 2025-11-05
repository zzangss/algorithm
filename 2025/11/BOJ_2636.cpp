// BOJ 2636 - 치즈

#include<iostream>
#include<queue>

using namespace std;

typedef pair<int, int> pi;

// 동 서 남 북
int dir_r[4] = { 1, 0, -1, 0 };
int dir_c[4] = { 0, 1, 0, -1 };

bool isBoardEmpty(int board[101][101], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1) {
                return false;
            }
        }
    }
    return true;
}

int cntCornerCheese(int board[101][101], int n, int m) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 2) {
                cnt++;
                board[i][j] = 0;
            }
        }
    }
    return cnt;
}

/*
void printBoard(int board[101][101], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
*/

void bfs(int board[101][101], bool visited[101][101], int row, int col) {
    queue<pair<int, int>> q;
    q.push({ 0,0 });
    visited[0][0] = true;

    while (!q.empty()) {
        int now_r = q.front().first;
        int now_c = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_r = now_r + dir_r[i];
            int next_c = now_c + dir_c[i];

            if (next_r >= 0 && next_r < row && next_c >= 0 && next_c < col && !visited[next_r][next_c]) {
                if (board[next_r][next_c] == 1) {
                    board[next_r][next_c] = 2;
                    visited[next_r][next_c] = true;
                }
                else {
                    q.push({ next_r, next_c });
                    visited[next_r][next_c] = true; // 꼭 넣을때 방문 체크를 해줘야한다!! 
                }
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 입력 
    int n, m; // 가로 n 세로 m
    cin >> n >> m;

    int board[101][101] = { 0 };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int is_cheese;
            cin >> is_cheese;
            board[i][j] = is_cheese;
        }
    }
    //cout << endl; 

    // 연산
    int cnt = 0;
    while (!isBoardEmpty(board, n, m)) {
        cnt++;
        bool visited[101][101] = { false };
        //printBoard(board, n,m);
        cntCornerCheese(board, n, m);
        bfs(board, visited, n, m);
    }

    // 출력 
    cout << cnt << "\n" << cntCornerCheese(board, n , m);
}