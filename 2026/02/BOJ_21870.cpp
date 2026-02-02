// boj 21870 시철이가 사랑한 GCD 

#include<iostream>
#include<vector>

using namespace std;

int GCD(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int solve(int n, const vector<int>& a, int idx) {
    //기저 조건
    if (n == 1) {
        return a[idx];
    }

    // 앞의 절반 원소를 선택
    int left_cnt = n / 2;
    int right_cnt = n - left_cnt;

    int gcd1 = a[idx];
    for (int i = idx; i < idx + left_cnt; i++) {
        gcd1 = GCD(gcd1, a[i]);
    }
    gcd1 += solve(right_cnt, a, idx + left_cnt);

    // 뒤의 절반 원소를 선택
    right_cnt = n / 2;
    left_cnt = n - right_cnt;

	int gcd2 = a[idx + right_cnt];
    for (int i = idx + right_cnt + 1 ; i < idx + n; i++) {
        gcd2 = GCD(gcd2, a[i]);
    }
    gcd2 += solve(right_cnt, a, idx);

    return max(gcd1, gcd2);
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << solve(n, a, 0);
}