#include<iostream>
#include<vector>

using namespace std;

string isWheel(int n, int k) {
	vector<char> wheel(n, NULL);
	vector<bool> check(26, true);
	bool canMake = true;
	string result = "";

	int num, location = 0; char c;
	while (k--) {
		cin >> num >> c;
		location = (location + num) % n;
		if (wheel[location] == NULL && check[c - 'A']) {
			wheel[location] = c;
			check[c - 'A'] = false;
		}
		else if (wheel[location] == c) continue;
		else return "!";
	}

	for(int i = 0; i< n; i++) {
		if (wheel[(n + location) % n] == NULL) result += '?';
		else result += wheel[(n + location) % n];
		location--;
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	string result = isWheel(n, k);
	
	cout << result;
}