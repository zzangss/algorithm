#include<iostream>
#include <vector>

using namespace std;

vector<vector<int>> v; // 가족관계 저장
vector<bool> visited; //방문한 사람 확인
int result = -1; //결과값 저장

void DFS(int n, int target, int d) {
	if (n == target) {
		result = d; //원하는 사람을 만나면 그때의 촌수 저장
	}

	for (int num : v[n]) {
		if (!visited[num]) {
			visited[num] = true;
			DFS(num, target, d + 1); 
			visited[num] = false;
		}
	}

}

int main() {

	//입력
	int n, p1, p2, m;
	cin >> n;
	cin >> p1 >> p2;
	cin >> m;

	v.resize(n+1);
	visited.assign(n + 1, false);

	while (m--) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	
	//연산
	visited[p1] = true;
	DFS(p1, p2, 0);

	//출력
	cout << result;

	return 0;
}