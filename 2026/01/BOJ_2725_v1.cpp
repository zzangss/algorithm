// boj 2725 보이는 점의 개수 

// boj 2725 보이는 점의 개수

#include<iostream>
#include<vector>
#define MAX 1001

using namespace std;

int gcd(int a, int b){
    if(b > a){
        swap(a, b);
    }
    while(b){
        a %= b;
        swap(a,b);
    }
    return a;
}

int solve(int n, vector<int>& dp){
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
                if(gcd(i, k) == 1){
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

    // dp값 초기 셋팅
    dp[0] = 0;
    dp[1] = 3;

    // 정답 계산
    while(c--){
        int n;
        cin >> n;

        cout << solve(n, dp) << "\n";
    }

    return 0;
}