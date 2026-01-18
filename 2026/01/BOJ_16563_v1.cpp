#include<iostream>
#include<vector>
#define MAX 5000001

using namespace std;

vector<bool> prime_check;
vector<int> prime;

// 에라토스테네스의 체 
vector<int> findPrime(int n){
    prime_check.resize(n+1, true);

    for(int i = 2; i * i <= n; i++){
        if(prime_check[i]){
            for(int j = i*i; j <= n; j += i){
                prime_check[j] = false;
            }
        }
    }

    for(int i = 2; i <= n; i++){
        if(prime_check[i]){
            prime.push_back(i);
        }
    }

    return prime;
}

vector<int> solve(int ki){
    vector<int> result;

    int idx = 0;
    while(ki > 0){
        if(prime_check[ki]){
            result.push_back(ki);
            break;
        }
        if(ki % prime[idx] == 0){
            result.push_back(prime[idx]);
            ki /= prime[idx];
        }
        else{
            idx++;
        }
    }

    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        
    int n;
    cin >> n;

    // 소수 집합 미리 찾아놓기. 
    findPrime(MAX);

    for(int i = 0; i<n; i++){
        int ki;
        cin >> ki;

        vector<int> result;
        result = solve(ki);

        for(int i = 0; i < result.size(); i++){
            cout << result[i] << " ";
        }
        cout << "\n";
    }
}