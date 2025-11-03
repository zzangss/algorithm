// BOJ 2108 - 통계학

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solve(vector<int>& input, int n) {
    vector<int> result(4);

    // 정렬
    sort(input.begin(), input.end());

    //중앙값
    result[1] = input[n / 2];

    // 산술평균, 최빈값
    double sum = 0;
    int check[8005] = { 0 };
    for (int i = 0; i < input.size(); i++) {
        sum += input[i];
        check[input[i] + 4000]++;
    }
    result[0] = round(sum / n);

    int max_idx = 0;
    int count = 0;
    for (int i = 0; i < 8001; i++) {
        if (check[i] > check[max_idx]) {
            count = 0;
            max_idx = i;
        }
        if (check[i] == check[max_idx] && count < 2) {
            count++;
            max_idx = i;
        }
    }
    result[2] = max_idx - 4000;

    //범위
    result[3] = input[n - 1] - input[0];

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int n;
    cin >> n;

    vector<int> input;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        input.push_back(num);
    }

    vector<int> answer = solve(input, n);

    cout << answer[0] << "\n" << answer[1] << "\n" << answer[2] << "\n" << answer[3];



    return 0;
}