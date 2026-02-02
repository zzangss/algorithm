// boj 15918 랭퍼든 수열쟁이야!!

#include<iostream>
#include<vector>

using namespace std;

int arr[25];
bool used[13] = {false,};

int solve(int n, int idx){
    // 기저조건
    if(idx > 2 * n){ // 수열이 가득 찼다면 랭퍼드 수열이 완성되었다는 의미. 
        return 1;
    }

    if(arr[idx] != -1){ // 살펴보려는 현재 위치에 이미 숫자가 채워져있다면 다음 위치로 바로 이동
        return solve(n, idx+1);
        
    }
    int result = 0;
    
    for(int i = 1; i <= n; i++){
        // i만큼의 수를 사이에 둘 수 있는지 확인 (수열의 전체 크기로 확인)
        if(idx + i + 1 <= 2 * n){
            // i번째 수가 사용되지 않았고, 현재 위치 idx와 i만큼 사이에 두고 떨어진 위치에 이미 수가 없는지 확인
            if(!used[i] && arr[idx + i + 1] == -1 && arr[idx] == -1){
                arr[idx] = arr[idx + i + 1] = i;
                used[i] = true;
                result += solve(n, idx+1);
                arr[idx] = arr[idx + i + 1] = -1;
                used[i] = false;
            }
        }
    }
    
    return result;
}

int main(){
    // 입력
    int n, x, y;
    cin >> n >> x >> y;

    // 수열 초기화 
    for(int i = 1; i <= 2*n; i++){
        arr[i] = -1;
    }
    arr[x] = arr[y] = y - x - 1; // x, y 위치에 들어갈 수는 정해져있음. 고정해놓고 시작. 
    used[y-x-1] = true;

    // 연산 및 출력 
    cout << solve(n, 1);

    return 0;
}