#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string name; cin >> name;
	int alpha[26] = { 0, }; //알파벳 개수 세는 배열
	int odd = 0; //알파벳의 개수가 홀수인 경우를 세는 변수
	int num = 0; //그 개수가 홀수인 알파벳이 하나인 경우엔 해당 알파벳을 알아야하기 때문에 그 인덱스를 표시하는 변수
	string result = ""; //결과값 저장

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
			for (int k = 0; k < alpha[i]/2; k++) { //팰린드롬이기 때문에 절반만 세어줘도 OK 
				result += (i + 'A');
			}
		}
	}
	
	if (odd == 1) result += num + 'A';//홀수인 수가 있는 경우엔 중간에 추가해주어야 함.
	for (int i = result.size() - 1; i >= 0; i--) {
		if (odd == 1 && i == result.size() - 1) { //홀수인 수는 건너뛰기
			continue;
		}
		result += result[i];
	}

	cout << result;

	

}