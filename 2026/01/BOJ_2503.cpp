// boj 2503 숫자 야구
#include<iostream>
#include<vector>
#define MAX 1001

using namespace std;

vector<bool> check;

void initCheckBoard(){
    check.resize(MAX, true);
    for(int i = 0; i<MAX; i++){
        int a, b, c;
        int temp = i;
        a = temp % 10;
        temp /=10;
        b = temp % 10;
        temp /= 10;
        c = temp % 10;

        if(a == b || b == c || c == a){
            check[i] = false;
        }

        if(a == 0 || b == 0 || c == 0){
            check[i] = false;
        }
    }
}

void checkNum(int num, int s, int b){
    for(int i = 0; i<MAX; i++){
        int n_s = 0, n_b = 0;
        if(check[i]){
            vector<int> n_num(3);
            int temp = i;
            n_num[0] = temp % 10;
            temp /=10;
            n_num[1] = temp % 10;
            temp /= 10;
            n_num[2] = temp % 10;
            
            temp = num;
            for(int k = 0; k < 3; k++){
                int now = temp % 10;
                if(now == n_num[k]){
                    n_s++;
                }
                else{
                    if(now == n_num[(k+1) % 3] || now == n_num[(k+2) % 3]){
                        n_b++;
                    }
                }
                temp /= 10;
            }

            if(s != n_s || b != n_b){
                check[i] = false;
            }
        }
    }
}

int cntCheckBoard(){
    int cnt = 0;
    for(int i = 0; i<MAX; i++){
        if(check[i]){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    initCheckBoard();
    for(int i = 0; i<n; i++){
        int num, s, b;
        cin >> num >> s >> b;

        checkNum(num, s, b);
    }

    cout << cntCheckBoard();

    return 0;
}