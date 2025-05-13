#include<iostream>
#include<vector>

using namespace std;

int main() {

	string s;
	int n;
	cin >> s >> n;

	


	int tmp = 1;
	int result = 0;
	for (int i = s.size() - 1; i >= 0; i--) {
		if (s[i] <= '9' && s[i]>='0') {
			result += (s[i] - '0')*tmp;
		}
		else {
			result += (s[i] - 'A' + 10) * tmp;
		}
		tmp *= n;
	}

	cout << result;
}