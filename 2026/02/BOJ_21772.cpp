// boj 21772 가희의 고구마 먹방

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int r, c, t, max_cnt = 0;
int dir_row[5] = {1, -1, 0, 0, 0};
int dir_col[5] = {0, 0, 1, -1, 0};

void solve(int row, int col, vector<vector<char>>& map, int depth, int cnt){
    if(depth == t){
        max_cnt = max(max_cnt, cnt);
        return;
    }

    int result;
    for(int i = 0; i < 5; i++){
        int next_row = row + dir_row[i];
        int next_col = col + dir_col[i];

        if(next_row >= 0 && next_row < r && next_col >= 0 && next_col < c){
            if(map[next_row][next_col] != '#'){
                if(map[next_row][next_col] == 'S'){
                    map[next_row][next_col] = '.';
                    cnt++;
                    solve(next_row, next_col, map, depth+1, cnt);
                    cnt--;
                    map[next_row][next_col] = 'S';
                }
                else{
                    solve(next_row, next_col, map, depth+1, cnt);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c >> t;

    int row, col;
    vector<vector<char>> map(r, vector<char>(c));
    for(int i = 0; i<r; i++){
        for(int k = 0; k<c; k++){
            cin >> map[i][k];
            if(map[i][k] == 'G'){
                row = i;
                col = k;
                map[i][k] = '.';
            }
        }
    }

    solve(row, col, map, 0, 0);
    
    cout << max_cnt;
}