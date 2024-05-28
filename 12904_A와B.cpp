#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	int size = str2.size();
	int answer = 0;
	while (true) {
		if (str1 == str2) { 
			answer = 1;
			break;
		}
		if (str2.size() == 0) break;

		if (str2[str2.size() - 1] == 'A') {
			str2 = str2.substr(0, str2.size()-1);
		}
		else {
			str2 = str2.substr(0, str2.size() - 1);
			reverse(str2.begin(), str2.end());
		}
	}

	cout << answer;
}