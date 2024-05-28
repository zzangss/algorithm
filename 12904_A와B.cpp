#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int greedy(string s1, string s2) {
	if (s1 == s2) return 1;
	if (s1.size() > s2.size()) return 0;

	if (s2.find(s1 + "A") != string::npos) {
		return greedy(s1 + "A", s2);
	}
	reverse(s1.begin(), s1.end());
	if (s2.find(s1 + "B") != string::npos) {
		return greedy(s1 + "B", s2);
	}

	return 0;
}
int main() {
	string str1, str2;
	cin >> str1 >> str2;

	int result = greedy(str1, str2);
	cout << result;
}