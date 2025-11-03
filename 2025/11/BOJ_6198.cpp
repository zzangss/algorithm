// BOJ 6198 옥상 정원 꾸미기

#include <iostream>
#include <stack>
#define MAX 80001

using namespace std;

long long solve(int n, int building_height[]) {
    stack<int> s;

    long long result = 0;

    for (int i = 0; i < n; i++) {
        if (!s.empty()) {
            if (s.top() > building_height[i]) {
                result += s.size();
                s.push(building_height[i]);
            }
            else {
                while (!s.empty() && s.top() <= building_height[i]) {
                    s.pop();
                }
                result += s.size();
                s.push(building_height[i]);
            }
        }
        else {
            s.push(building_height[i]);
        }
    }

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

    int building_height[MAX] = { 0 };
    for (int i = 0; i < n; i++) {
        int height;
        cin >> height;
        building_height[i] = height;
    }

    //연산
    cout << solve(n, building_height);

    return 0;
}