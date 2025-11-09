// BOJ 2096 - 내려가기

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> dp_min(3, 0);
    vector<int> dp_max(3, 0);
    vector<int> temp_dp_min(3, 0);
    vector<int> temp_dp_max(3, 0);

    for (int i = 0; i < n; i++) {
        int now[3]; // n번째 줄의 값
        cin >> now[0] >> now[1] >> now[2];
        

        for (int i = 0; i < 3; i++) {
            if (i == 1) {
                temp_dp_min[i] = now[i] + min(dp_min[0], min(dp_min[1], dp_min[2]));
                temp_dp_max[i] = now[i] + max(dp_max[0], max(dp_max[1], dp_max[2]));
            }
            else {
                temp_dp_min[i] = now[i] + min(dp_min[i], dp_min[1]);
                temp_dp_max[i] = now[i] + max(dp_max[i], dp_max[1]);
            }
        }

        dp_min = temp_dp_min;
        dp_max = temp_dp_max;
    }

    // n번째 줄에서의 최댓값, 최솟값 계산 
    int rmax = 0, rmin = 1e9;
    for (int i = 0; i < 3; i++) {
        rmax = max(rmax, dp_max[i]);
        rmin = min(rmin, dp_min[i]);
    } 

    cout << rmax << " " << rmin;

    return 0;
}