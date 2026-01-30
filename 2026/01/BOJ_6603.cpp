// boj 6603 로또

#include<iostream>
#include<vector>

using namespace std;

void printSeq(const vector<int>& s, const vector<bool>& visited){
    for(int i = 0; i < s.size(); i++){
        if(visited[i]){
            cout << s[i] << " ";
        }
    }
    cout << endl;
}

void solve(int k, int s_idx, int depth, const vector<int>& s, vector<bool>& visited) {
    if (k - s_idx < 6 - depth) { // 더블체크
        return;
    }
    if (depth == 6) {
        printSeq(s, visited);
        return;
    }

    for (int i = s_idx; i < k; i++) {
        if (!visited[i] && k - i >= 6 - depth) { // i에서부터 남은 숫자의 수가 수 6개를 선택하기에 충분한 경우에만 재귀 탐색
            visited[i] = true;
            solve(k, i, depth + 1, s, visited);
            visited[i] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    while (true) {
        int k;
        cin >> k;

        if (k == 0) {
            break;
        }

        vector<int> s(k);
		vector<bool> visited(k, false);
        for (int i = 0; i < k; i++) {
            cin >> s[i];
        }

        solve(k, 0, 0, s, visited);

        cout << endl;
    }

    return 0;
}