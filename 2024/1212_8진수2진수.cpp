#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	string str;
	cin >> str;

	vector<int>result;

	for (int i = 0; i < str.size(); i++) {
		int temp = str[i] - '0';
		result.push_back(temp/ 4);
		temp = temp % 4;
		result.push_back(temp/ 2);
		temp = temp % 2;
		result.push_back(temp / 1);
	}
	
	int k;
	for (k = 0; k < result.size(); k++) {
		if (result[k] != 0) {
			break;
		}
	}

	if (k == result.size()) {
		cout << 0;
		return 0;
	}

	for (int i = k; i < result.size(); i++) {
		cout << result[i];
	}

	return 0;

}