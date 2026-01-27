// boj 2992 크면서 작은 수

#include<iostream>

using namespace std;

// 정수 a, b의 구성이 같은지 판단하는 함수
bool isSame(int a, int b){
    int arr[10] = {0,};
    while(a > 0){
        arr[a % 10]++;
        a /= 10;
    }
    while(b > 0){
        arr[b % 10]--;
        b /= 10;
    }

    for(int i = 0; i<10; i++){
        if(arr[i] > 0 || arr[i] < 0){
            return false;
        }
    }
    return true;
}

int solve(int x){
    for(int i = x + 1; i < 1000000; i++){
        if(isSame(x, i)){
            return i;
        }
    }

    return 0;
}

int main(){
    int x;
    cin >> x;

    cout << solve(x);

    return 0;
}