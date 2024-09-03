#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

//��Ŭ���� ȣ���� �̿��ؼ� �ִ����� ���ϴ� �Լ�
int getGCD(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}
/*
int getGCD(int a, int b){
	if(b==0){
	return a;
	}
	return getGCD(b, a%b);
}
*/

vector<int> findM(int n, vector<int>& numbers) {
	vector<int> result;

	// ������ ���� �ִ� ����� ���
	int gcd = numbers[1] - numbers[0];
	for (int i = 2; i < n; i++) {
		gcd = getGCD(gcd, numbers[i] - numbers[i - 1]);
	}

	//������ ��� m -> �ִ������� ��� ã��
	for (int i = 2; i * 2 <= gcd; i++) {
		if (gcd % i == 0) {
			result.push_back(i);
		}
	}
	result.push_back(gcd); //���� gcd �ֱ�

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//�Է�
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	//����
	sort(v.begin(), v.end());
	vector<int> result = findM(n, v);

	//���
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	return 0;
}