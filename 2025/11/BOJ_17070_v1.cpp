// BOJ 17070 - 파이프 옮기기 1 by DFS, 백트래킹 

#include<iostream>
#include<vector>

using namespace std;

typedef pair<int, int> pi;

int cnt = 0;
void solve(const vector<vector<int>>& grid, int n, pi f_pipe, pi s_pipe) {
    if (s_pipe.first > n || s_pipe.second > n) {
        return;
    }

    int r = 0, c = 0;

    r = s_pipe.first - f_pipe.first;
    c = s_pipe.second - f_pipe.second;

    // 벽지랑 이동 동선이 겹치는 경우
    if (r == 1 && c == 1) {
        if (grid[s_pipe.first][s_pipe.second] == 1 ||
            grid[s_pipe.first - 1][s_pipe.second] == 1 ||
            grid[s_pipe.first][s_pipe.second - 1] == 1) {
            return;
        }
    }
    else {
        if (grid[s_pipe.first][s_pipe.second] == 1) return;
    }
    if (s_pipe.first == n && s_pipe.second == n) {
        cnt++;
        return;
    }


    int next_f_r = s_pipe.first;
    int next_f_c = s_pipe.second;
    // 대각선
    if (r == 1 && c == 1) {
        solve(grid, n, s_pipe, { next_f_r , next_f_c + 1 });
        solve(grid, n, s_pipe, { next_f_r + 1, next_f_c });
        solve(grid, n, s_pipe, { next_f_r + 1, next_f_c + 1 });
    }
    // 세로
    else if (r == 1 && c == 0) {
        solve(grid, n, s_pipe, { next_f_r + 1, next_f_c });
        solve(grid, n, s_pipe, { next_f_r + 1, next_f_c + 1 });
    }
    // 가로
    else if (r == 0 && c == 1) {
        solve(grid, n, s_pipe, { next_f_r , next_f_c + 1});
        solve(grid, n, s_pipe, { next_f_r + 1, next_f_c + 1 });
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }
    solve(grid, n, { 1,1 }, { 1,2 });

    cout << cnt;
}