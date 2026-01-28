// boj 2992 크면서 작은 수 (use next_permutation)

#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;



int solve(int n){
    // 순열 벡터 배열 생성 및 초기화
    vector<int> oper;
    int temp = n;
    
    while(temp > 0){
        oper.push_back(temp % 10);
        temp /= 10;
    }
    
    sort(oper.begin(), oper.end());
    
    // next_permutation 함수 이용해서 문제 풀기  
    do{
        int compare = 0;
        for(int i = 0; i < oper.size(); i++){
            compare = oper[i] + compare * 10;
        }
        if(compare > n){
            return compare;
        }
    }
    while(next_permutation(oper.begin(), oper.end()));
    
    return 0;
}

int main(){
    int n;
    cin >> n;
    
    cout << solve(n);
    
    return 0;
}