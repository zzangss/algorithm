#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main() {
	int n, m; cin >> n >> m;

	vector<string> v(n);
	map<string, int> word;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		word[v[i]] = 1;
	}

	int result = 0;

	for (int i = 0; i < m; i++) {
		string str; cin >> str;
		if (word[str] == 1) {
			result++;
		}
	}

	cout << result;

}