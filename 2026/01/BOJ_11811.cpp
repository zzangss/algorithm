// boj 11811 데스스타

#include<iostream>
#include<vector>

using namespace std;

vector<int> solve(int n, const vector<vector<int>>& mtx){
    vector<int> result(n, 0);
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            result[i] |= mtx[i][j];
        }
    }
    
    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<vector<int>> mtx(n, vector<int>(n,0));
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            int aij;
            cin >> aij;
            mtx[i][j] = aij;
        }
    }
    
    vector<int> result = solve(n, mtx); 
    
    for(int i = 0; i<n; i++){
        cout << result[i] << " ";
    }
}