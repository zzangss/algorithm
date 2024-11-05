#include<iostream>
#include<vector>

using namespace std;

bool check(vector<int>& v, int n, int h) {
	//��ġ 0���� ù ���ε� ������ �Ÿ�, ��ġ n���� ������ ���ε� ������ �Ÿ���
	//h ������ ũ�� ���ε��� ���� �� �������� ����.
	if (v[0] - 0 > h || n - v[v.size() - 1] > h) {
		return false;
	}
	//���ε� ���̻��� Ȯ���غ���
	//���ʿ��� �����ִ�, �Ÿ��� ���ε� ������ 1/2 ���ϸ� ���� ��� ���� �� ����.
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i + 1] - v[i] > h * 2) {
			return false;
		}
	}
	return true;
}

int solve(vector<int>& v, int n) {
	int s = 0, e = n, m;
	int result = n;

	while (s <= e) {
		m = (s + e) / 2;

		if (check(v, n, m)) {
			result = m;
			e = m - 1; //��������� ���� �� ���� �� ����. �׷��� ���ε� ���̸� �� �ٿ�����.
		}
		else {
			s = m + 1; //���� �� ���� �� ������ ���ε� ���� �ø���
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;
	vector<int> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}

	cout << solve(v, n);
}