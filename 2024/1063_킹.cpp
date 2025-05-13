#include<iostream>
#include<vector>
#define SIZE_OF_BOARD 8

using namespace std;

bool range(int row, int column) {
	//체스판의 범위를 넘어가면 false, 넘어가지 않으면 true를 반환하는 함수
	if (row < 0 || column < 0 || row >= 8 || column >= 8) {
		return false;
	}
	return true;
}

void game(const vector<string>& shifting, vector<int>& king, vector<int>& stone) {
	for (int i = 0; i < shifting.size(); i++) {
		int r = king[0], c = king[1]; //이동한 경우의 행, 열의 위치를 임시로 담을 변수
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

		if (range(r, c)) { //이동한 결과 킹의 위치가 범위를 벗어나지 않았다면
			int tr = r + r - king[0], tc = c + c - king[1]; //돌이 킹에게 밀린 경우의 위치
			if (r == stone[0] && c == stone[1] && range(tr, tc)) { //킹이 이동한 위치에 돌이 있는 경우, 그리고 킹에게 밀린 돌이 체스판의 범위를 넘지 않는 경우
				//킹의 위치를 업데이트
				king[0] = r;
				king[1] = c;
				//체스판의 돌의 위치를 업데이트
				stone[0] = tr;
				stone[1] = tc;
			}
			else if (r != stone[0] || c != stone[1]) { //킹이 이동한 위치에 돌이 없는 경우
				king[0] = r;
				king[1] = c;
			}
		}
	}	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
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

	//출력
	cout << char(king[1] + 'A') << king[0] + 1 << endl;
	cout << char(stone[1] + 'A') << stone[0] + 1;
	
	return 0;
}