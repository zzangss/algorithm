#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> v;
vector <bool > visited;

int BFS(int n) {
	int result = 0;
	queue<int> q;
	q.push(n);
	visited[n] = true; //방문한 컴퓨터는 표시하기

	while (!q.empty()) {
		//(이전에 방문하지 않은) 현재 컴퓨터와 연결된 컴퓨터를 하나씩 큐에 넣으면서 세어준다.
		for (int num : v[q.front()]) {
			if (!visited[num]) { //방문하지 않은 경우에만 큐에 넣기
				q.push(num); 
				visited[num] = true;
				result++; // 큐에 넣어진 것은 건너건너서라도 1번 컴퓨터에서부터 온 것이니, 바이러스에 감염된 것이다.
			}
		}
		q.pop(); //현재 컴퓨터에 연결된 컴퓨터는 다 세고 pop. 순서대로 다음 컴퓨터를 보면서 연결된 애들을 세어준다.
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//입력
	int n, m; cin >> n >> m;

	v.resize(n + 1);
	visited.assign(n + 1,false);

	//연산
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a); // 서로 연결이 되어있다는 것을 알 수 있게 저장
	}
	
	int result = BFS(1);

	//출력
	cout << result;
}