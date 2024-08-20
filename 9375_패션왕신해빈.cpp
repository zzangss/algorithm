#include<iostream>
#include<map>
#include<vector>

using namespace std;

int main() {
	int t; cin >> t;

	

	for (int i = 0; i < t; i++) {
		int n; cin >> n;
		map <string, int> clothes;
		vector<string> v;
		for (int k = 0; k < n; k++) {
			string name, kind;
			cin >> name >> kind;
			if (clothes[kind] == 0) {
				v.push_back(kind);
			}
			clothes[kind] += 1;
		}
		int result = 1;
		for (int i = 0; i < v.size(); i++) {
			result *= clothes[v[i]] + 1;
		}

		cout << result - 1 << endl;
	}
	
	

	return 0;
}