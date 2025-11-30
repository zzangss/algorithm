// BOJ 1520 - 내리막길

#include <iostream>
#include <vector>
#define MAX 501

using namespace std;

int dir_r[4] = {0, 0, -1, 1};
int dir_c[4] = {-1, 1, 0, 0};

vector<vector<int>> dp;
int dfs(const vector<vector<int>>& map, int r, int c, int m, int n){
    if(r == m - 1 && c == n - 1){
        return 1;
    }
    if(dp[r][c] != -1) {
        return dp[r][c];
    }
    
    dp[r][c] = 0;
    
    for(int i = 0; i < 4; i++){
        int next_r = r+dir_r[i];
        int next_c = c+dir_c[i];
        
        if(next_r < m && next_r >=0 && next_c < n && next_c >=0){
            if(map[next_r][next_c] < map[r][c]){
                dp[r][c] += dfs(map, next_r, next_c, m, n);
            }
        }
    }
    
    return dp[r][c];
}

int main()
{
    int m,n;
    cin >> m >> n;
    
    vector<vector<int>> map (m, vector<int> (n,0));
    for(int i = 0; i < m; i++){
        for (int j = 0; j< n; j++){
            cin >> map[i][j];
        }
    }
    dp.assign(m, vector<int>(n, -1));
    cout << dfs(map, 0, 0, m, n);
    
    return 0;
}