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
	visited[n] = true; //�湮�� ��ǻ�ʹ� ǥ���ϱ�

	while (!q.empty()) {
		//(������ �湮���� ����) ���� ��ǻ�Ϳ� ����� ��ǻ�͸� �ϳ��� ť�� �����鼭 �����ش�.
		for (int num : v[q.front()]) {
			if (!visited[num]) { //�湮���� ���� ��쿡�� ť�� �ֱ�
				q.push(num); 
				visited[num] = true;
				result++; // ť�� �־��� ���� �ǳʰǳʼ��� 1�� ��ǻ�Ϳ������� �� ���̴�, ���̷����� ������ ���̴�.
			}
		}
		q.pop(); //���� ��ǻ�Ϳ� ����� ��ǻ�ʹ� �� ���� pop. ������� ���� ��ǻ�͸� ���鼭 ����� �ֵ��� �����ش�.
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	//�Է�
	int n, m; cin >> n >> m;

	v.resize(n + 1);
	visited.assign(n + 1,false);

	//����
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a); // ���� ������ �Ǿ��ִٴ� ���� �� �� �ְ� ����
	}
	
	int result = BFS(1);

	//���
	cout << result;
}