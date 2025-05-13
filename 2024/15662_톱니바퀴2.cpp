#include<iostream>
#include<vector>

using namespace std;

void clock(vector<vector<int>>& wheel, int num) {
	int temp = wheel[num][7];
	for (int i = 7; i > 0; i--) {
		wheel[num][i] = wheel[num][i - 1];
	}
	wheel[num][0] = temp;
}

void counterClock(vector<vector<int>>& wheel, int num) {
	int temp = wheel[num][0];
	for (int i = 0; i < 7; i++) {
		wheel[num][i] = wheel[num][i + 1];
	}
	wheel[num][7] = temp;
}

void rotateWheel(vector<vector<int>>& wheel, vector<int>& check) {
	for (int i = 0; i < check.size(); i++) {
		if (check[i] == -1) {
			counterClock(wheel, i);
		}
		else if (check[i] == 1) {
			clock(wheel, i);
		}
	}
}

void checkWheel(vector<vector<int>>& wheel, vector<int>& check,int num, int d, char go) {
	if (num < 0 || num > wheel.size() - 1) { // 왼쪽, 오른쪽으로 더 바퀴가 없음
		return;
	}
	check[num] = d;

	if (num - 1 >= 0 && go == 'L') { 
		if (wheel[num - 1][2] != wheel[num][6]) {
			checkWheel(wheel, check, num - 1, d * -1, 'L');
		}
	}
	else if (num + 1 <= wheel.size() - 1 && go == 'R') {
		if (wheel[num][2] != wheel[num + 1][6]) {
			checkWheel(wheel, check, num + 1, d * -1, 'R');
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int t; cin >> t;
	vector<vector<int>> wheel(t, vector<int>(8, 0));
	vector<int> check;

	for (int i = 0; i < t; i++) {
		string str; cin >> str;
		for (int j = 0; j < 8; j++) {
			if (str[j] == '1') {
				wheel[i][j] = 1;
			}
		}
	}

	int k; cin >> k;

	//입력 + 연산

	for (int i = 0; i < k; i++) {
		int num, d; // 회전할 n번a째 바퀴, 회전 방향.
		cin >> num >> d;
		check.assign(t, 0);
		checkWheel(wheel, check, num - 1, d, 'L'); // 기준 바퀴의 왼쪽 바퀴 확인
		checkWheel(wheel, check, num - 1, d, 'R');
		rotateWheel(wheel, check);
	}

	int result = 0;

	for (int i = 0; i < t; i++) {
		if (wheel[i][0] == 1) {
			result++;
		}
	}

	//출력
	cout << result;

	return 0;
}