#include<iostream>
#include <vector>

using namespace std;

vector<vector<int>> v; // �������� ����
vector<bool> visited; //�湮�� ��� Ȯ��
int result = -1; //����� ����

void DFS(int n, int target, int d) {
	if (n == target) {
		result = d; //���ϴ� ����� ������ �׶��� �̼� ����
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

	//�Է�
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
	
	//����
	visited[p1] = true;
	DFS(p1, p2, 0);

	//���
	cout << result;

	return 0;
}