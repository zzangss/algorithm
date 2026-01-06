// BOJ 1005 - ACM Craft

#include<iostream>
#include<vector>
#include<math.h>
/*
DP + topdown으로 풀어본다!
if) 건물 n을 짓기위해  a, b 건물을 지어야한다고 가정
 -> 점화식 : DP[n] = max(DP[a], DP[b]) + D[n]
    (이때 D[n]은 n번째 건물을 짓기 위해 걸리는 시간.
     DP[n]은 n까지의 건물을 짓기위해 걸리는 최소 시간.)
*/

using namespace std;

vector<int> DP; //size : n
int solve(int w, const vector<int>& D, const vector<vector<int>>& adjacent){
    if(DP[w] != -1){
        return DP[w];
    }

    int max_time = 0;
    for(int prev : adjacent[w]){
        max_time = max(max_time, solve(prev, D,adjacent));
        //cout << prev << "->" << w << "=" << DP[prev] << endl;
    }
    DP[w] = max_time + D[w];
    //cout << w << "=" << DP[w] << endl;

    return DP[w];
}

int main()
{
    // 입력
    int t, n, k; // 테스트케이스 개수, 건물 개수, 건설순서 규칙 수 
    cin >> t;
    
    vector<int> result;
    while(t--){
        cin >> n >> k;
    
        vector<int> D(n + 1); //n번째 건물을 지을때 걸리는 시간
        for(int i = 1; i <= n; i++){
            cin >> D[i];
        }
    
        vector<vector<int>> adjacent(n + 1, vector<int> (0)); //인접리스트 이용 
        for(int i = 0; i < k; i++){
            int x, y;
            cin >> x >> y;
            adjacent[y].push_back(x); // top down 사용하기 위해 반대로 입력!
        }
    
        int w;
        cin >> w;
    
        // 연산 
        DP.assign(n + 1, -1);
    
        solve(w, D, adjacent);
    
        result.push_back(DP[w]);
    }
    
    for(int i = 0; i<result.size(); i++){
        cout << result[i] << "\n";
    }

    return 0;
}