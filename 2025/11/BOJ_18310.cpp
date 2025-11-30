// BOJ 18310 - 안테나 

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<long long> location(n, 0);
    for(int i = 0; i<n; i++){
        cin >> location[i];
    }

    sort(location.begin(), location.end());

    cout << location[location.size() / 2];

    return 0;
}