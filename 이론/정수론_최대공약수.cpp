#include<iostream>

using namespace std;

/*
// 가장 직관적인 방법
// 시간복잡도 O(n)
int GCD(int a, int b) {
	for (int i = min(a, b); i > 1; i--) {
		if (a % i == 0 && b % i == 0) {
			return i;
		}
	}
	return 0;  //서로소인 경우
}
*/

/*
// 유클리드 호제법을 이용
// 반복문으로 구현 
// 시간복잡도 O(log n)
int GCD(int a, int b) { // a > b
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}
*/

// 유클리드 호제법을 이용
// 재귀로 구현
// 시간복잡도 O(log n)
int GCD(int a, int b) {
	if (b == 0) return a;
	return GCD(b, a % b);
}

int main() {
	int a, b;
	cin >> a >> b;

	cout << GCD(a, b);
}
