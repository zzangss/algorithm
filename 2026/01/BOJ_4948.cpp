// boj 4948 베르트랑 공준

#include<iostream>
#include<vector>

using namespace std;

const int MAX = 123456 * 2;

vector<bool> checkPrime(int n){
    vector<bool> prime_table(n + 1, true);
    
    prime_table[0] = false;
    prime_table[1] = false;
    for(long long i = 2; i * i <= n; i++){
        if(prime_table[i]){
            for(long long k = i * i; k <=n; k+=i){
                prime_table[k] = false;
            }
        }
    }

    return prime_table;
}

int cntPrime(int n, const vector<bool>& prime_table){
    int cnt = 0;
    for(int i = n + 1; i <= 2*n; i++){
        if(prime_table[i]){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    vector<bool> prime_table = checkPrime(MAX);

    while(true){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }

        cout << cntPrime(n, prime_table) << "\n";
    }

    return 0;
}