// boj 10819 차이를 최대로

#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int calValue(int n, const vector<int>& arr) {
    int sum = 0;

    for (int i = 1; i < n; i++) {
        sum += abs(arr[i - 1] - arr[i]);
    }

    return sum;
}

int solve(int n, vector<int>& arr) {
    int max_result = 0;

    do {
        max_result = max(max_result, calValue(n, arr));
    } while (next_permutation(arr.begin(), arr.end()));

    return max_result;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    cout << solve(n, arr);

    return 0;
}