// boj 1740 거듭제곱

#include<iostream>

using namespace std;

long long solve(long long n){
    long long result = 0;
    long long power_of_three = 1; // 3^powerofthree 순서대로 커질 예정
    
    while(n > 0){
        if(n % 2 == 1){
            result += power_of_three;
        }
        n /= 2;
        power_of_three *= 3;
    }
    
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long n; // 범위가 500,000,000,000 이하이기 때문에 longlong 사용
    cin >> n;
    
    cout << solve(n);
    
    return 0;
}