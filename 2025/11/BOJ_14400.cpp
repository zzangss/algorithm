// BOJ 14400 - 편의점 2

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

long long calDistance(vector<int> location, int shop){
    long long sum = 0;
    
    for(int i = 0; i<location.size(); i++){
        sum += abs(shop - location[i]);
    }

    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> x(n);
    vector<int> y(n);
    for(int i = 0; i < n; i++){
        cin >> x[i] >> y[i];
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    int result_x = x[(n - 1) / 2];
    int result_y = y[(n - 1) / 2];

    cout << calDistance(x, result_x) + calDistance(y, result_y);

    return 0;
}