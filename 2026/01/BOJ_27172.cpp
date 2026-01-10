#include<iostream>
#include<vector>
#define MAX 1000005

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 플레이어의 수 입력
    int n;
    cin >> n;

    // 각 플레이어의 카드 입력
    vector<int> player(n); // player[i] : i번째 플레이어 카드의 숫자.
    vector<int> card(MAX, MAX); // 플레이어가 카드를 가지고 있는지, 그리고 그 카드를 가진 플레이어의 점수는 무엇인지 저장할 배열
    for (int i = 0; i < n; i++) {
        cin >> player[i];
        card[player[i]] = 0;
    }

    for (int i = 0; i < n; i++) {
        int now_card = player[i]; //현재 플레이어의 카드 number

        // 1. 1은 무조건 ok
        if (card[1] != MAX) {
            card[1]++;
            card[now_card]--;
        }
        // 2. 1이 아닌 다른 약수들 확인하고 점수 계산 (trial division)
        for (int i = 2; i * i <= now_card; i++) {
            if (now_card % i == 0) {
                if (card[i] != MAX) {
                    card[i]++;
                    card[now_card]--;
                }
                if (now_card / i != i && card[now_card / i] != MAX) {
                    card[now_card / i]++;
                    card[now_card]--;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
		cout << card[player[i]] << " ";
    }

    return 0;
}