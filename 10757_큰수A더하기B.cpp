#include<iostream>
#include<algorithm>

using namespace std;

string add(string a, string b) {
	string ans = "";
	int temp = 0;

	int i, size = max(a.size(), b.size());

	if (a.size() < size) {
		for (int i = a.size(); i < size; i++) {
			a += '0';
		}
	}
	if (b.size() < size) {
		for (int i = b.size(); i < size; i++) {
			b += '0';
		}
	}

	for(i = 0; i < size; i++) {
		temp += (int)(a[i] - '0') + (int)(b[i] - '0');
		ans += (char)(temp % 10 + '0');
		temp /= 10;
	}
	if ((char)(temp % 10 + '0') != '0') {
		ans += (char)(temp % 10 + '0');
	}

	return ans;
}

int main() {
	string a, b, result;
	cin >> a >> b;

	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	result = add(a, b);

	reverse(result.begin(), result.end());

	cout << result;
}

