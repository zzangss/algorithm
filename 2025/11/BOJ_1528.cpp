// BOJ 1528 - 금민수의 합

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 1000000
#define INF 1e9

using namespace std;

vector<int> findGoldMinso(int n) {
	vector<int> goldminso;
	queue<int> q;

	q.push(4);
	goldminso.push_back(4);
	q.push(7);
	goldminso.push_back(7);
	while(!q.empty()) {
		goldminso.push_back(q.front());

		if(q.front() * 10 + 4 <= n) {
			q.push(q.front() * 10 + 4);
		}
		if(q.front() * 10 + 7 <= n) {
			q.push(q.front() * 10 + 7);
		}
		q.pop();
	}
	
    sort(goldminso.begin(), goldminso.end());
    
    return goldminso;
}

vector<int> solve(int n){
    vector<int> dp (n + 1, INF);
    vector<int> gms = findGoldMinso(n);
    vector<int> result;
    
    dp[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <gms.size(); j++){
            if(i - gms[j] < 0){
                break;
            }
            if(dp[i] > dp[i - gms[j]] + 1){
                dp[i] = dp[i - gms[j]] + 1;
            }
        }
    }
    
    if(dp[n] == INF){
        result.push_back(-1);
        return result;
    }
    
    int temp = n;
    while(temp > 0){
        for(int i = 0; i < gms.size(); i++){
            if(dp[temp-gms[i]] == dp[temp] - 1){
                result.push_back(gms[i]);
                temp = temp - gms[i];
                break;
            }
        }
    }
    
    sort(result.begin(), result.end());
    
    return result;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

    vector<int> result = solve(n);
    
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }

	return 0;
}