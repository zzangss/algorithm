#include<iostream>
#include<stack>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str; cin >> str;
	stack<char> s;
	int result = 0;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push('(');
		}
		else {
			if (str[i - 1] == '(') {
				s.pop();
				result += s.size();
			}
			else {
				s.pop();
				result++;
			}
		}
	}

	cout << result;
	return 0;
}