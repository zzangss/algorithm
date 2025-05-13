#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int priority(char ch) {
	switch (ch) {
	case '(': return 0;
	case '+': case'-': return 1;
	case '*': case'/':return 2;
	}
}

string postfix(string str) {
	string result = "";
	stack<char> s;

	for (int i = 0; i < str.size(); i++) {
		char c = str[i];

		switch (c) {
		case '(' : 
			s.push(c);
			break;
		case ')':
			while (!s.empty() && s.top() != '(') {
				result += s.top();
				s.pop();
			}
			s.pop();
			break;
		case '+' : case '-': case '*' : case'/':
			while (!s.empty() && priority(s.top()) >= priority(c)) {
				result += s.top();
				s.pop();
			}
			s.push(c);
			break;
		default:
			result += c;
		}
	}

	while (!s.empty()) {
		result += s.top();
		s.pop();
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	string str; cin >> str;

	cout << postfix(str);

	return 0;
}