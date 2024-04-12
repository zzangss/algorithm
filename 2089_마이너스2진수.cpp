#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> result;
	
	if (n == 0) {
		cout << 0;
		return 0;
	}
	while (n !=  0) {
		if (n % -2 == 0) {
			result.push_back(0);
			n = n / -2;
		}
		else {
			result.push_back(1);
			n = (n - 1) / -2;
		}
	}

	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i];
	}
}