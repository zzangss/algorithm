//BOJ 1697 - ¼û¹Ù²ÀÁú

#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pi;

int bfs(int source, int dest) {
    queue<pi> q;
    bool visited[100001] = { false };

    q.push({ source, 0 });
    visited[source] = true;

    while (!q.empty()) {
        int num = q.front().first, depth = q.front().second;
        q.pop();
        if (num == dest) {
            return depth;
        }
        if (num + 1 >= 0 && num + 1 < 100001) {
            if (!visited[num + 1]) {
                visited[num + 1] = true;
                q.push(make_pair(num + 1, depth + 1));
            }
        }
        if (num - 1 >= 0 && num - 1 < 100001) {
            if (!visited[num - 1]) {
                visited[num - 1] = true;
                q.push(make_pair(num - 1, depth + 1));
            }
        }
        if (2 * num >= 0 && 2 * num < 100001) {
            if (!visited[2 * num]) {
                visited[2 * num] = true;
                q.push(make_pair(2 * num, depth + 1));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    cout << bfs(a, b);

    return 0;
}