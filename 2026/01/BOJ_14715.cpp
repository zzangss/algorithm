// BOJ 14715 전생했더니 슬라임 연구자였던 건에 대하여 (Easy)

#include<iostream>
#include<vector>

using namespace std;

vector<int> makePrime(int n){
    vector<bool> prime_table(n+1, true);
    vector<int> prime;

    for(int i = 2; i * i <= n; i++){
        if(prime_table[i]){
            for(int j = i * i; j <= n; j += i){
                prime_table[j] = false;
            }
        }
    }

    for(int i = 2; i <= n; i++){
        if(prime_table[i]){
            prime.push_back(i);
        }
    }
    
    return prime;
}

int solve(int n){
    // 1. 소수 집합 구하기 
    vector<int> prime;
    prime = makePrime(n);

    // 2. 정수 n의 소인수의 개수 구하기 
    int idx = 0, cnt = 0;
    while(n != 1){
        if(n % prime[idx] == 0){
            n /= prime[idx];
            cnt++;
        }
        else{
            idx++;
        }
    }

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