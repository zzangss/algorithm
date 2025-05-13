#include<iostream>
#include<vector>
#define SIZE_OF_BOARD 8

using namespace std;

bool range(int row, int column) {
	//ü������ ������ �Ѿ�� false, �Ѿ�� ������ true�� ��ȯ�ϴ� �Լ�
	if (row < 0 || column < 0 || row >= 8 || column >= 8) {
		return false;
	}
	return true;
}

void game(const vector<string>& shifting, vector<int>& king, vector<int>& stone) {
	for (int i = 0; i < shifting.size(); i++) {
		int r = king[0], c = king[1]; //�̵��� ����� ��, ���� ��ġ�� �ӽ÷� ���� ����
		for (int j = 0; j < shifting[i].size(); j++) {
			switch(shifting[i][j]) {
			case 'R':
				c++;
				break;
			case 'L':
				c--;
				break;
			case 'B':
				r--;
				break;
			case 'T':
				r++;
				break;
			}
		}

		if (range(r, c)) { //�̵��� ��� ŷ�� ��ġ�� ������ ����� �ʾҴٸ�
			int tr = r + r - king[0], tc = c + c - king[1]; //���� ŷ���� �и� ����� ��ġ
			if (r == stone[0] && c == stone[1] && range(tr, tc)) { //ŷ�� �̵��� ��ġ�� ���� �ִ� ���, �׸��� ŷ���� �и� ���� ü������ ������ ���� �ʴ� ���
				//ŷ�� ��ġ�� ������Ʈ
				king[0] = r;
				king[1] = c;
				//ü������ ���� ��ġ�� ������Ʈ
				stone[0] = tr;
				stone[1] = tc;
			}
			else if (r != stone[0] || c != stone[1]) { //ŷ�� �̵��� ��ġ�� ���� ���� ���
				king[0] = r;
				king[1] = c;
			}
		}
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//�Է�
	string l1, l2;
	int n;
	cin >> l1 >> l2 >> n;

	vector<string> shifting(n);
	vector<int> king(2);
	vector<int> stone(2);

	king[0] = l1[1] - '1';
	king[1] = l1[0] - 'A';
	stone[0] = l2[1] - '1';
	stone[1] = l2[0] - 'A';


	for (int i = 0; i < n; i++) {
		cin >> shifting[i];
	}

	game(shifting, king, stone);

	//���
	cout << char(king[1] + 'A') << king[0] + 1 << endl;
	cout << char(stone[1] + 'A') << stone[0] + 1;
	
	return 0;
}