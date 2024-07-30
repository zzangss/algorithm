#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k; cin >> n >> k;
	
	vector<char> wheel(n, NULL); //바퀴 완성시키기
	int rotation = 0; //현재 위치
	bool check = false; //바퀴를 완성시킬 수 없는 경우 true로 바꿔줌
	bool alpha[26] = { false, }; //사용한 알파벳 체크할 배열


	for (int i = 0; i < k; i++) {
		int s; cin >> s; 
		char c; cin >> c;

		//인덱스 범위 조절로 회전 형태를 맞추어줌
		if (rotation + s >= n) rotation = (rotation + s % n) % n; //이 부분 주의. s의 범위가 100까지이기 때문에 나머지 연산 사용.
		else rotation += s;

		
		if (wheel[rotation] != NULL && wheel[rotation] != c) {
			//만약 현재 칸이 NULL이 아니고 입력된 문자와 같지도 않다면 바퀴를 만들 수 없음.
			check = true;
		}
		else { 
			//남은 경우는 
			// 1. 현재 칸이 비어있는 경우 -> 알파벳을 사용했는지 확인 
			// 2. 현재 칸의 문자와 입력받은 문자가 같은 경우 -> 별다른 확인 필요X
			if (alpha[c - 'A'] == true && wheel[rotation] == NULL) {
				//현재 칸이 비어있지만, 입력받은 값이 이미 사용된 알파벳이라면 
				//중복된 문자는 사용할 수 없기 때문에 회전 바퀴를 만들 수 없는 경우가 됨. (1번 경우)
				check = true;
			}
			else wheel[rotation] = c;
		}

		alpha[c - 'A'] = true; //사용한 알파벳은 표시하기

		// 마지막 입력에 도달했으므로 현재까지 만들어진 바퀴 출력
		if (i == k - 1) {
			if (check) { //바퀴를 만드는 것이 불가능한 경우
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