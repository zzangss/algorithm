// BOJ 1621 - 조삼모사 

#include <iostream>
#include <stack>
#define MAX 1000001

using namespace std;

struct Result {
    int time;
    stack<int> locate;
};

int banana_w[MAX];
int dp[MAX] = { 0 };
int traceback[MAX] = { 0 }; // 1이면 하나씩 가져온 경우, 2이면 k개씩 가져온 경우

Result solve(int n, int k, int c) {
    Result result;

    for (int i = 1; i < k; i++) {
        dp[i] = banana_w[i] + dp[i - 1];
        traceback[i] = 1;
    }

    for (int i = k; i <= n; i++) {
        if (dp[i - 1] + banana_w[i] > dp[i - k] + c) {
            dp[i] = dp[i - k] + c;
            traceback[i] = 2;
        }
        else {
            dp[i] = dp[i - 1] + banana_w[i];
            traceback[i] = 1;
        }
    }

    result.time = dp[n];

    int i = n;
    while (i > 0) {
        if (traceback[i] == 2) {
            result.locate.push(i - k + 1);
            i = i - k;
        }
        else {
            i--;
        }
    }

    return result;
}

int main()
{
    int n;
    cin >> n;

    int k, c;
    cin >> k >> c;

    for (int i = 1; i <= n; i++) {
        int weight;
        cin >> weight;
        banana_w[i] = weight;
    }

    Result result = solve(n, k, c);

    cout << result.time << "\n" << result.locate.size() << "\n";

    int size = result.locate.size();
    for (int i = 0; i < size; i++) {
        cout << result.locate.top() << " ";
        result.locate.pop();
    }

    return 0;
}