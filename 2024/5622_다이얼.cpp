#include<iostream>
#include<string>

using namespace std;

int main() {
	string s;
	cin >> s;

	int result = 0;

	for (int i = 0; i < s.size(); i++) {
		result += (s[i]- 65) / 3 + 3;
	    if (s[i] == 'S' || s[i] == 'V' || s[i] == 'Y' || s[i] == 'Z') result--;
	}

	cout << result;
}