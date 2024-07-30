#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k; cin >> n >> k;
	
	vector<char> wheel(n, NULL); //���� �ϼ���Ű��
	int rotation = 0; //���� ��ġ
	bool check = false; //������ �ϼ���ų �� ���� ��� true�� �ٲ���
	bool alpha[26] = { false, }; //����� ���ĺ� üũ�� �迭


	for (int i = 0; i < k; i++) {
		int s; cin >> s; 
		char c; cin >> c;

		//�ε��� ���� ������ ȸ�� ���¸� ���߾���
		if (rotation + s >= n) rotation = (rotation + s % n) % n; //�� �κ� ����. s�� ������ 100�����̱� ������ ������ ���� ���.
		else rotation += s;

		
		if (wheel[rotation] != NULL && wheel[rotation] != c) {
			//���� ���� ĭ�� NULL�� �ƴϰ� �Էµ� ���ڿ� ������ �ʴٸ� ������ ���� �� ����.
			check = true;
		}
		else { 
			//���� ���� 
			// 1. ���� ĭ�� ����ִ� ��� -> ���ĺ��� ����ߴ��� Ȯ�� 
			// 2. ���� ĭ�� ���ڿ� �Է¹��� ���ڰ� ���� ��� -> ���ٸ� Ȯ�� �ʿ�X
			if (alpha[c - 'A'] == true && wheel[rotation] == NULL) {
				//���� ĭ�� ���������, �Է¹��� ���� �̹� ���� ���ĺ��̶�� 
				//�ߺ��� ���ڴ� ����� �� ���� ������ ȸ�� ������ ���� �� ���� ��찡 ��. (1�� ���)
				check = true;
			}
			else wheel[rotation] = c;
		}

		alpha[c - 'A'] = true; //����� ���ĺ��� ǥ���ϱ�

		// ������ �Է¿� ���������Ƿ� ������� ������� ���� ���
		if (i == k - 1) {
			if (check) { //������ ����� ���� �Ұ����� ���
				cout << '!';
				return 0;
			}
			for (int j = 0; j < n; j++) {
				if (rotation < 0) rotation += n;
				if (wheel[rotation] == NULL) {
					cout << '?';
				}
				else {
					cout << wheel[rotation];
				}
				rotation--;
			}
		}
	}

	return 0;

}