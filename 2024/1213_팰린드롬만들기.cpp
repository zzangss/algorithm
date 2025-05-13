#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<int> countAlpha(string name) {
	vector<int> alpha(26, 0);

	for (int i = 0; i < name.size(); i++) {
		alpha[name[i] - 'A']++;
	}

	return alpha;
}

string makePalin(vector<int> alpha) {
	string p1 = "", p2 = "", p3 = "";

	for (int i = 0; i < 26; i++) {
		if (alpha[i] % 2 == 1) {
			if (p2.size() == 1) {
				return "I'm Sorry Hansoo";
			}
			p2 = (char)(i + 'A');
		}
		for (int k = 0; k < alpha[i] / 2; k++) {
			p1 += (char)(i + 'A');
			p3 = (char)(i + 'A') + p3;
		}
	}

	return p1 + p2 + p3;
}

string solve(string name) {
	vector<int> alpha = countAlpha(name);
	return makePalin(alpha);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string name; cin >> name;

	cout << solve(name);

	return 0;
}