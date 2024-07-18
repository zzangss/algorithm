#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main() {
	string str; cin >> str;

	vector<int> alpha(26, 0);

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 97 && str[i] <= 122) {
			alpha[str[i] - 97]++;
		}
		else {
			alpha[str[i] - 65]++;
		}
	}
	char result;
	int max_num = 0;
	for (int i = 0; i < 26; i++) {
		if (max_num < alpha[i]) {
			max_num = alpha[i];
			result = i + 65;
		}
		else if( max_num == alpha[i]){
			result = '?';
		}
	}

	cout << result;
}