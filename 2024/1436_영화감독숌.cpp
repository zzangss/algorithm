#include<iostream>
#include<vector>
#include<string>
#define MAX 10000

using namespace std;

string makeTitle(int n) {
	int num = 666; //666�� ù ��ȭ ����. 666���� ����
	string temp;
	while(n){
		temp = to_string(num); //Ȯ���� ���� ���ڿ��� �ٲپ� find �Լ� �̿�
		if (temp.find("666") != string::npos) { //���� 666�� ������ ��ȭ ������ ������ Ƚ�� ����
			n--;
		}
		num++;
	}

	return temp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;

	cout << makeTitle(n);

	return 0;
}