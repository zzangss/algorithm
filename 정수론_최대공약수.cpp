#include<iostream>

using namespace std;

/*
// ���� �������� ���
// �ð����⵵ O(n)
int GCD(int a, int b) {
	for (int i = min(a, b); i > 1; i--) {
		if (a % i == 0 && b % i == 0) {
			return i;
		}
	}
	return 0;  //���μ��� ���
}
*/

/*
// ��Ŭ���� ȣ������ �̿�
// �ݺ������� ���� 
// �ð����⵵ O(log n)
int GCD(int a, int b) { // a > b
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}
*/

// ��Ŭ���� ȣ������ �̿�
// ��ͷ� ����
// �ð����⵵ O(log n)
int GCD(int a, int b) {
	if (b == 0) return a;
	return GCD(b, a % b);
}

int main() {
	int a, b;
	cin >> a >> b;

	cout << GCD(a, b);
}