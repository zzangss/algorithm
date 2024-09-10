#include<iostream>
#include<vector>
#include<string>
#define MAX 10000

using namespace std;

string makeTitle(int n) {
	int num = 666; //666이 첫 영화 제목. 666부터 시작
	string temp;
	while(n){
		temp = to_string(num); //확인할 수를 문자열로 바꾸어 find 함수 이용
		if (temp.find("666") != string::npos) { //만약 666을 포함한 영화 제목이 맞으면 횟수 차감
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