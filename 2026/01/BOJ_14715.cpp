// BOJ 14715 전생했더니 슬라임 연구자였던 건에 대하여 (Easy)

#include<iostream>
#include<vector>

using namespace std;

// trial prime 개념 이용 
int factorize(int n){
    int cnt = 0;
    for(int i = 2; i * i <= n; i++){
        while(n % i == 0){
            cnt++;
            n /= i;
        }
    }

    if(n > 1){
        cnt++;
    }

    return cnt;
}

int solve(int n){

    int cnt = factorize(n);

    // 3. log2(cnt)하여 2^(k-1) < log2(cnt) <= 2^(k) 이면 result는 k (분할할 때 이진트리 형태로 분할됨.)
    if(cnt == 1){
        return 0;
    }
    else{
        int comp = 2;
        int result = 1;
        while(true){
            if(cnt <= comp){
                return result;
            }
            else{
                comp *= 2;
                result++;
            }
        }
    }
    
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    cout << solve(n);

    return 0;
}