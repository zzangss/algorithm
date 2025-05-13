#include<iostream>
#include<vector>

using namespace std;

vector<int>check(1000, -1);

int dP(int num) {
	if (num == 1) return 1;
	if (num == 2) return 2;
	if (num == 3) return 4;
	//기저 설정 주의. 초기값.

	if (check[num] != -1) {
		return check[num];
	}

	check[num] =  dP(num - 1) + dP(num - 2) + dP(num - 3);
	return check[num];
}

int main() {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int num;
		cin >> num;
		cout << dP(num) <<"\n";
	}
}