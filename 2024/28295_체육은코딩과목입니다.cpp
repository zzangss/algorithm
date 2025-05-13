#include<iostream>

using namespace std;

int main() {
	int sum = 1;

	for (int i = 0; i < 10; i++) {
		int n;
		cin >> n;
		sum += n;
	}

	int result = sum % 4;

	if (result == 1) cout << 'N';
	else if (result == 2) cout << 'E';
	else if (result == 3) cout << 'S';
	else cout << 'W';
}