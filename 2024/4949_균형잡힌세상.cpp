#include<iostream>
#include<string>
#include<stdio.h>
#include<stack>

using namespace std;

string balance(string s) {
	stack<char> brackets;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(' || s[i] == '[') {
			brackets.push(s[i]);
		}
		if (s[i] == ')') {
			if (brackets.empty() || brackets.top() != '(') {
				return "no";
			}
			else brackets.pop();
		}
		if (s[i] == ']') {
			if (brackets.empty() || brackets.top() != '[') {
				return "no";
			}
			else brackets.pop();
		}
		if (s[i] == '.') {
			if (brackets.empty()) return "yes";
			else return "no";
		}
	}
}

int main() {

	while (true) {
		string s;	
		getline(cin, s);
		if (s == ".") break;
		cout << balance(s) << endl;
	}

	return 0;
}

