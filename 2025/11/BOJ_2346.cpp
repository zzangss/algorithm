// BOJ 2346 - «≥º± ≈Õ∂ﬂ∏Æ±‚

#include <iostream>
#include <deque>
#define MAX 1001

using namespace std;

typedef pair<int, int> pi;

pi shiftBalloon(pi balloon, deque<pi>& dq) {
    if (balloon.second > 0)
    {
        pi temp;
        for (int i = 0; i < balloon.second - 1; i++) {
            temp = dq.front();
            dq.pop_front();
            dq.push_back(temp);
        }
        temp = dq.front();
        dq.pop_front();
        return temp;
    }
    else {
        pi temp;
        for (int i = 0; i < abs(balloon.second) - 1; i++) {
            temp = dq.back();
            dq.pop_back();
            dq.push_front(temp);
        }
        temp = dq.back();
        dq.pop_back();
        return temp;
    }
}

void solve(deque<pi> dq) {
    pi balloon = dq.front();
    cout << balloon.first << " ";
    dq.pop_front();

    while (!dq.empty()) {
        balloon = shiftBalloon(balloon, dq);
        cout << balloon.first << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    deque<pi> dq;
    for (int i = 0; i < n; i++) {
        int b_num;
        cin >> b_num;
        dq.push_back(make_pair(i + 1, b_num));
    }

    solve(dq);

    return 0;
}