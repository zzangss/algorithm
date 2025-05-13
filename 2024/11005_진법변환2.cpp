#include<iostream>
#include<vector>

using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	int a, b;


	char alpha[37] = { 'a', };
	vector<char>result;

	for (int i = 10; i <= 36; i++) {
		alpha[i] = 'A' - 10 + i;
	}

	a = n;
	b = 0;

	while (true) {
		if (a < m) {
			break;
		}
		b = a % m;
		a /= m;

		if (b < 10) {
			result.push_back('0' + b);
		}
		else {
			result.push_back(alpha[b]);
		}

	}

	if (a < 10) {
		result.push_back('0' + a);
	}
	else {
		result.push_back(alpha[a]);
	}

	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i];
	}

}