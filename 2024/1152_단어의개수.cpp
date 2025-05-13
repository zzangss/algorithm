#include<iostream>
#include<string>

using namespace std;

int main() {
	string s;
	getline(cin, s);

	int result = 0;

	if (s.length() == 1 && s[0] == ' ') {
		cout << 0;
		return 0;
	}

	for (int i = 1; i < s.length()-1 ; i++) {
		if (s[i] == ' ') {
			result++;
		}
	}


	cout << result + 1;
}