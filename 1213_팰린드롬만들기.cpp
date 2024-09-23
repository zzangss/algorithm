#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> cntAlpha(string str) {
	vector<int> cnt_alpha(26, 0);
	for (int i = 0; i < str.size(); i++) {
		cnt_alpha[str[i] - 'A']++;
	}
	return cnt_alpha;
}

string makePalin(vector<int> alpha) {
	string part1 = "", part2 = "", part3 = "";

	for (int i = 0; i < 26; i++) {
		if(count)
	}
}

string solve(string str) {
	vector<int> alpha = cntAlpha(str);
	return 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string str; cin >> str;

	cout << solve(str);

	return 0;
}