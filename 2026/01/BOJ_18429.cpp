// boj 18429 근손실

#include<iostream>
#include<vector>

using namespace std;

int n, k;
bool used[10] = {false,};

int solve(int weight, int day, int kit[10]){
    // 기저조건 
    if(weight < 500){ // 중량 500 이상의 조건을 만족하지 않는 경우 (for문 안에서 확인하긴 하는데, 더블체크하기.)
        return 0;
    }
    if(weight >= 500 && day == n){ // 중량 500 이상이고, 마지막 날이면
        return 1;
    }

    int result = 0;

    for(int i = 0; i < n; i++){
        int next_weight = weight - k + kit[i];
        if(!used[i] && next_weight >= 500){
            used[i] = true;
            result += solve(next_weight, day + 1, kit);
            used[i] = false;
        }
    }

    return result;
}

int main(){
    cin >> n >> k;

    int kit[10] = {0,};

    for(int i = 0; i<n; i++){
        int input;
        cin >> input;
        kit[i] = input;
    }

    cout << solve(n, k, 500, 1, kit);

    return 0;
}