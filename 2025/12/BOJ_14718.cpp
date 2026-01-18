// BOJ 14718 - 용감한 용사 진수

#include<iostream>
#include<vector>
#define INF 1e9

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;

    vector<vector<int>> v(n, vector<int>(3));
    for(int i = 0; i<n; i++){
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }

    // 가장 스탯이 낮은 적 하나 찾아서 스탯 업데이트. 이를 기준으로 다른 스탯도 업데이트 할 예정. 
    vector<bool> visited(n, false);
    int a = 0, b = 0, c = 0;
    int min = INF;
    for(int i = 0; i<n; i++){
        if(v[i][0] + v[i][1] + v[i][2] < INF){
            a = v[i][0];
            b = v[i][1];
            c = v[i][2];
        }
    }
    
    // k - 1 번 n명의 병사들을 순회하며 가장 작은 스텟을 가질 수 있도록 업데이트 
    for(int i = 1; i < k; i++){
        int temp = a + b + c; // 현재까지의 스탯의 합을 임시로 저장
        min = INF;
        int min_idx = -1;
        for(int j = 0; j < n; j++){
            // 이미 싸워서 이긴 병사라면 pass
            if(visited[j]){
                continue;
            }

            // 싸우려는 병사의 스탯이 내 현재 스탯보다 크면, 스탯 증가시키기. 
            if(a < v[j][0]){
                temp = temp - a + v[j][0];
            }
            if(b < v[j][1]){
                temp = temp - b + v[j][1];
            }
            if(c < v[j][2]){
                temp = temp - c + v[j][2];
            }

            // 가장 적은 스탯으로 싸울 수 있는 j번째 병사 선별.
            if(min > temp){
                min = temp;
                min_idx = j;
            }
            temp = a + b + c;
        }
        a = v[min_idx][0];
        b = v[min_idx][1];
        c = v[min_idx][2];
        visited[temp_min_idx] = true;
    }

    cout << a + b + c;

    return 0;

}