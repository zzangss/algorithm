// boj 2725 보이는 점의 개수 

// boj 2725 보이는 점의 개수

#include<iostream>
#include<vector>
#define MAX 1001

using namespace std;

// 조건을 만족하는 점은 y = x 직선에 대칭적으로 존재. 직선의 좌측만 마킹하도록 설정.
void markPoint(int n, vector<vector<bool>>& grid){
    grid[0][0] = false;
    for(int i = 1; i < n; i++){
        for(int k = 0; k <= i; k++){
            // 1. 만약 조건을 만족하는 점인 경우
            //    (x + i, y + k)씩 둘 중 하나가 n에 도달할때까지 마킹. 
            if(grid[i][k]){
                int x = i + i;
                int y = k + k; // 현재점 (i, k)는 조건을 만족하는 점이기 때문에 그 다음 점부터 시작 
                while(x <= n && y <= n){
                    grid[x][y] = false;
                    x += i;
                    y += k;
                }
            }
        }
    }
}

int solve(int n, vector<int>& dp, const vector<vector<bool>>& grid){
    // 1. 이미 점의 개수를 구한 케이스라면
    if(dp[n] != -1){
        return dp[n];
    }

    // 2. 아닌경우 이전에 계산해두었던 값을 이용해 다음 계산에 이용.
    for(int i = 2; i <= n; i++){
        if(dp[i] != -1){
            continue;
        }
        else{
            int cnt = 0;
            for(int k = 0; k < i; k++){
                if(grid[i][k]){
                    cnt++;
                }
            }
            dp[i] = dp[i-1] + (cnt * 2);
        }
    }

    return dp[n];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int c; //c : testcase # 
    cin >> c;

    vector<int> dp(MAX, -1);
    vector<vector<bool>> grid(MAX, vector<bool>(MAX, true)); // true : 조건 만족하는 점, false : 조건을 불만족하는 점

    // 1. 조건을 만족하는 점 계산
    markPoint(MAX - 1, grid);

    // dp값 초기 셋팅
    dp[0] = 0;
    dp[1] = 3;

    // 2. 정답 계산
    while(c--){
        int n;
        cin >> n;

        cout << solve(n, dp, grid) << "\n";
    }

    return 0;
}