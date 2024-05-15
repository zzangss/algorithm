#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> v;
vector<int> check;
int result = 0;

void BFS(int node) {
	queue<int> q;
	q.push(node);
	check[node] = 1;

	while (!q.empty()) {
		int first;
		first = q.front();
		q.pop();

		for (int i : v[first]) {
			if (check[i] == 0) {
				q.push(i);
				check[i] = 1;
				result++;
			}

		}

	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num, connect;

	cin >> num;
	cin >> connect;

	v.resize(num + 1);
	check.resize(num + 1, 0);

	for (int i = 0; i < connect; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	BFS(1);

	cout << result;

	return 0;
}