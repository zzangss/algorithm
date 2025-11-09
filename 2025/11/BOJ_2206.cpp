// BOJ 2206 - 벽 부수고 이동하기

#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int dir_r[4] = { 1, -1, 0 , 0 };
int dir_c[4] = { 0, 0, 1, -1 }; // 상하우좌

int visited[1001][1001][2];

struct Point{
    int r;
    int c;
    bool chance; //chance : true -> 벽 부술 수 있음. 
};

int solve(const vector<vector<int>>& grid, int n, int m) { 
    queue<Point> q;
    q.push({ 1, 1, true });
    visited[1][1][0] = 1;

    while (!q.empty()) {
        Point now = q.front();
        q.pop();
        
        int next_r, next_c;
        for (int i = 0; i < 4; i++) {
            next_r = now.r + dir_r[i];
            next_c = now.c + dir_c[i];

            if (next_r < 1 || next_r > n || next_c < 1 || next_c > m) {
                continue; // 범위 벗어나면 반복 x 
            }
            if (grid[next_r][next_c] == 0) { // 벽 x 
                if (now.chance && visited[next_r][next_c][0] == 0) { // 벽 부술 기회 있을때 
                    visited[next_r][next_c][0] = visited[now.r][now.c][0] + 1;
                    q.push({ next_r, next_c,true });
                }
                else if(!now.chance && visited[next_r][next_c][1] == 0) { // 벽 부술 기회 없을때
                    visited[next_r][next_c][1] = visited[now.r][now.c][1] + 1;
                    q.push({ next_r, next_c, false });
                }
            }
            else {
                if (now.chance && visited[next_r][next_c][1] == 0) {
                    visited[next_r][next_c][1] = visited[now.r][now.c][0] + 1;
                    q.push({ next_r, next_c, false });
                }
            }
        }
    }

    int res0 = visited[n][m][0];
    int res1 = visited[n][m][1];
    if (res0 == 0 && res1 == 0) { // 둘 다 도달 못함
        return -1;
    }
    else if (res0 == 0) { 
        return res1;
    }
    else if (res1 == 0) { 
        return res0;
    }
    else { // 둘 다 도달
        return min(res0, res1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m; // n = row size, m = column size

    vector<vector<int>> grid(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int k = 1; k <= m; k++) {
            grid[i][k] = s[k-1] - '0';
        }
    }

    int result = solve(grid, n, m);

    cout << result;
    
    return 0;
}