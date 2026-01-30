// boj 16505 별

#include<iostream>
#include<math.h>

using namespace std;

bool arr[1025][1025] = { false, }; // true = *, false = 공백

void printStar(int n) {
    for (int i = 0; i < pow(2,n); i++) {
        for (int k = 0; k < pow(2,n) - i; k++) {
            if (arr[i][k]) {
				cout << "*";
            }
            else {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

// n에 해당하는 구조의 별을 찍는 함수.
void solve(int n, int row, int col) {
    // 기저 조건 
    if (n == 0) {
        arr[row][col] = true;
        return;
    }

    solve(n - 1, row, col);
    solve(n - 1, row + pow(2,n - 1), col);
    solve(n - 1, row, col + pow(2, n - 1));
}

int main() {
    int n;
    cin >> n;

    solve(n, 0, 0);
    printStar(n);

    return 0;
}