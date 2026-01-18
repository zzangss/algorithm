// boj 16563 어려운 소인수분해

#include<iostream>
#include<vector>
#define MAX 5000001

using namespace std;

vector<int> prime_check; // 가장 작은 소인수를 저장. 만약 i가 소수라면 i가 저장되고, 아니라면 이를 나눌 수 있는 가장 작은 소인수를 저장. 

// 에라토스테네스의 체 
void findPrime(int n){
    prime_check.resize(n+1);
    for(int i = 0; i<=n; i++){
        prime_check[i]=i;
    }

    for(int i = 2; i * i <= n; i++){
        if(prime_check[i] == i){
            for(int j = i*i; j <= n; j += i){
                if(prime_check[j] == j){
                    prime_check[j] = i;
                }
            }
        }
    }
}

void solve(int ki){
    int idx = 0;
    while(ki > 1){
        cout << prime_check[ki] << " ";
        ki /= prime_check[ki];
    }
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

        solve(ki);

        cout << "\n";
    }

    return 0;
}