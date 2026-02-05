// boj 24891 단어 마방진

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

int l, n;
vector<string> v;
vector<string> mabang;
vector<bool> visited;

bool solve(int idx){
    if(idx == l){
        return true;
    }

    bool isMabangExist = false;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            string cur = v[i];
            bool possible = true;

            // cur을 현재 idx 행에 놓을 수 있는지 판단.
            for(int k = 0; k < idx; k++){
                if(mabang[k][idx] != cur[k]){
                    possible = false;
                    break;
                }
            }

            if(possible){
                visited[i] = true;
                mabang[idx] = cur_word;

                if(solve(idx + 1)){
                    return true;
                }

                visited[i] = false;
                mabnag[idx] = "";
            }
        }
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> l >> n;

    v.resize(n);
    for(int i = 0; i<n; i++){
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    mabang.resize(l);
    visited.assign(N, false);

    if(solve(0)){
        for(int i = 0; i < l; i++){
            cout << mabang[i] << "\n";
        }
    }
    else{
        cout << "NONE";
    }

    return 0;
}