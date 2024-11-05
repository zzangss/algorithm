#include <iostream>
#include<algorithm>

using namespace std;

int plum[1001][3];
int T, W;

int DP() {
    int result = 0; // 최종 결과
    int count[1001][32][3]; // 자두 개수 세는 배열

    count[1][0][1] = plum[1][1];
    count[1][1][2] = plum[1][2];

    result = max(count[1][0][1], count[1][1][2]);

    for (int i = 2; i <= T; i++) {
        for (int j = 0; j <= W; j++) {
            count[i][j][1] = max(count[i - 1][j][1], count[i - 1][j - 1][2]) + plum[i][1];
            count[i][j][2] = max(count[i - 1][j - 1][1], count[i - 1][j][2]) + plum[i][2];

            result = max(max(result, count[i][j][1]), count[i][j][2]);
        }
    }

    return result;
}

int main() {
    cin >> T >> W;

    for (int i = 1; i <= T; i++) {
        int num;
        scanf("%d", &num);
        plum[i][num] = 1;
    }

    printf("%d\n", DP());
    return 0;
}
