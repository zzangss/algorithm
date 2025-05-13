#include<iostream>

using namespace std;

int main() {
	int e, s, m; cin >> e >> s >> m;

	if (e == 15) e = 0;
	if (s == 28) s = 0;
	if (m == 19) m = 0;

	int num = 1;
	while (true) {
		if (num % 15 == e && num % 28 == s && num % 19 == m) {
			cout << num;
			break;
		}
		num++;
	}

	return 0;
}