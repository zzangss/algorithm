// BOJ 2563 - 색종이

#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<vector<int>> board(101, vector<int>(101, 0));

    for(int i = 0; i < n; i++){
        int r, c;
        cin >> c >> r;

        for(int j = 0; j < 10; j++){
            for(int k = 0; k < 10; k++){
                board[r + j][c + k] = 1;
            }
        }
    }

    int cnt = 0;
    for(int j = 0; j < 100; j++){
        for(int k = 0; k < 100; k++){
            if(board[j][k] == 1){
                cnt++;
            }
        }
    }

    cout << cnt;

    return 0;
}