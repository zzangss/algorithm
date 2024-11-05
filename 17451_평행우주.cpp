#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//�Է�
	int n; cin >> n;
	vector<int> planet(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> planet[i]; // �༺ ���� �Է�
	}

	//����
	long long result = 0; // ���������� �ּ� ��߼ӵ� (���)
	for (int i = n - 1; i >= 0; i--) { 
		//n��° �༺���� 1��° �༺���� �Ųٷ� Ȯ���Ѵ�. 
		// 1. ���� ������� ����� result ������ �� �༺�� ������ ��� result�� �� �༺ �������� ������Ʈ. 
		// 2. ������� ����� result������ �� �༺ ������ ª�� ���
		// 2-1.(result�� �� �༺ ������ ����̸�) �ٲ��� �ʾƵ� �ȴ�.
		// 2-2.(result�� �� �༺ ������ ����� �ƴϸ�)result���� ū �� �༺���� ����� �Է��Ѵ�.
		if (result < planet[i]) { 
			result = planet[i];
		}
		else if(result > planet[i]) {
			if (result % planet[i] != 0) {
				result = (result / planet[i] + 1) * planet[i];
			}
		}
	}

	// ���
	cout << result;

	return 0;
}