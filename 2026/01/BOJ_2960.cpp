// boj 2960 에라토스테네스의 체
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int solve(int n, int k){
    vector<bool> num_set (n + 1, true); // 에라토스테네스의 체 알고리즘을 적용할 숫자 세트
    int result = 0;
    
    for(int i = 2; i <= n; i++){
        for(int j = i; j <= n; j += i){
            if(num_set[j]){ // 만약 아직 삭제하지 않은 숫자라면? 
                num_set[j] = false;
                //cout << j << endl;
                result++;
            }
            if(result == k){
                return j;
            }
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n,k;
    cin >> n >> k;
    
    cout << solve(n, k);
    
    return 0;
}