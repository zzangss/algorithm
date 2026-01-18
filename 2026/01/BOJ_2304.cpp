// boj 2304 창고 다각형

#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

int solve(int n, vector<pair<int,int>> histo){
    int result = 0;

    // 1. 가장 높이가 큰 기둥 찾기
    int max_idx = 0;
    for(int i = 0; i<n; i++){
        if(histo[max_idx].second < histo[i].second){
            max_idx = i;
        }
    }
    result += histo[max_idx].second;

    // 2. 왼쪽 확인.
    int temp_idx = 0;
    for(int i = 0; i <= max_idx; i++){ // 첫 좌표부터 시작. 
        if(histo[i].second >= histo[temp_idx].second){
            //cout << histo[i].first << " " << histo[temp_idx].first << " " << histo[temp_idx].second << " " << abs(histo[i].first - histo[temp_idx].first) * histo[temp_idx].second << endl;
            result += abs(histo[i].first - histo[temp_idx].first) * histo[temp_idx].second;
            temp_idx = i;
        }
    }

    //cout << "_____________" << endl;
    // 3. 오른쪽 확인 
    temp_idx = n - 1;
    for(int i = n - 1; i >= max_idx; i--){ // 첫 좌표부터 시작. 
        if(histo[i].second >= histo[temp_idx].second){
            //cout << histo[i].first << " " << histo[temp_idx].first << " " << histo[temp_idx].second << " " << abs(histo[i].first - histo[temp_idx].first) * histo[temp_idx].second << endl;
            result += abs(histo[i].first - histo[temp_idx].first) * histo[temp_idx].second;
            temp_idx = i;
        }
    }


    return result;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int,int>> histo(n); // {기둥 좌표, 기둥 높이}

    for(int i = 0; i<n; i++){
        cin >> histo[i].first >> histo[i].second;
    }

    sort(histo.begin(), histo.end());

    cout << solve(n, histo);

    return 0;
}