// boj 17297 Messi Gimossi 

#include<iostream>
#include<string>

using namespace std;

long long int dp[50];

void calLen(long long m) {
    dp[1] = 5;
    dp[2] = 13;
    int idx = 3;
    while (idx < 50) {
        dp[idx] = dp[idx - 1] + dp[idx - 2] + 1;
        idx++;
    }
}

char solve(int n, int m) {
    if (n == 1) {
        string s = "Messi";
        return s[m];
    }
    if (n == 2) {
        string s = "Messi Gimossi";
        return s[m];
    }

    if (dp[n - 1] > m) {
        return solve(n - 1, m);
    }
    else if (dp[n - 1] < m) {
        return solve(n - 2, m - dp[n - 1] - 1);
    }
    else if (dp[n - 1] == m) {
        return ' ';
    }
}

int main() {
    long long m;
    cin >> m;

    calLen(m);
    int n;

    for (int i = 0; i < 50; i++) {
        if (dp[i] > m) {
            n = i;
            break;
        }
    }

    char ans = solve(n, m - 1);



    if (ans == ' ') {
        cout << "Messi Messi Gimossi";
    }
    else {
        cout << ans;
    }

    return 0;
}