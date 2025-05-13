#include<iostream>
#include<vector>

using namespace std;

int main() {
	int a, b;

	cin >> a >> b;

	int A = 0, B = 0;

	int j = 1;
	for (int i = 100; i >= 1; i /= 10) {
		A += (a / i)* j;
		B += (b / i) * j;
		a %= i;
		b %= i;
		j *= 10;
	}

	int result = max(A, B);
	cout << result;

	return 0;
}