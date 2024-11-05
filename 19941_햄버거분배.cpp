#include <iostream>

using namespace std;

int main() {
	int n, k; cin >> n >> k;
	string table; cin >> table;

	int result = 0;

	for (int i = 0; i < n; i++) {
		if (table[i] == 'P') {
			for (int j = i - k; j <= i + k; j++) {
				if (j < 0 || j >= n || j == i) {
					continue;
				}
				if (table[j] == 'H') {
					table[j] = 'N';
					result++;
					break;
				}
			}
		}
	}

	cout << result;
}