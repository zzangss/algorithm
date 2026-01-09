// boj 1629 곱셈
#include<iostream>

using namespace std;

long long solve(int a, int b, int c) {
    long long result;

    if (b == 1) {
        return a % c;
    }
    else {
        result = solve(a, b / 2, c);
        if (b % 2 == 0) {
            result = result * result % c;
            return result;
        }
        else {
            result = result * result % c * a % c;
            return result;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, c;
    cin >> a >> b >> c;

    cout << solve(a, b, c);
}