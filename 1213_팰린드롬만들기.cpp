#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string name; cin >> name;
	int alpha[26] = { 0, }; //���ĺ� ���� ���� �迭
	int odd = 0; //���ĺ��� ������ Ȧ���� ��츦 ���� ����
	int num = 0; //�� ������ Ȧ���� ���ĺ��� �ϳ��� ��쿣 �ش� ���ĺ��� �˾ƾ��ϱ� ������ �� �ε����� ǥ���ϴ� ����
	string result = ""; //����� ����

	for (int i = 0; i < name.size(); i++) {
		alpha[name[i] - 'A']++;
	}

	for (int i = 0; i < 26; i++) {
		if (alpha[i] % 2 == 1) { 
			odd++; 
			num = i;
		}
	}
	if (odd > 1) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}
	else {
		for (int i = 0; i < 26; i++) {
			for (int k = 0; k < alpha[i]/2; k++) { //�Ӹ�����̱� ������ ���ݸ� �����൵ OK 
				result += (i + 'A');
			}
		}
	}
	
	if (odd == 1) result += num + 'A';//Ȧ���� ���� �ִ� ��쿣 �߰��� �߰����־�� ��.
	for (int i = result.size() - 1; i >= 0; i--) {
		if (odd == 1 && i == result.size() - 1) { //Ȧ���� ���� �ǳʶٱ�
			continue;
		}
		result += result[i];
	}

	cout << result;

	

}