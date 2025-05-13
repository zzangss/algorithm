#include<iostream>
#include<vector>

using namespace std;

void countAlpha(string word, vector<int>& alpha) {
	for (int i = 0; i < word.size(); i++) {
		alpha[word[i] - 'A']++;
	}
}

bool isSimilar(const vector<int> &main_word_alpha, string main, string compare) {
	vector<int> compare_word_alpha(26, 0);
	countAlpha(compare, compare_word_alpha);

	int diff = 0;

	for (int i = 0; i < 26; i++) {
		diff += abs(main_word_alpha[i] - compare_word_alpha[i]);
	}

	if (diff <= 1 || diff == 2 && main.size() == compare.size()) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;
	string main_word; cin >> main_word;

	vector<int> main_word_alpha(26, 0);
	countAlpha(main_word, main_word_alpha);

	int result = 0;
	for (int i = 0; i < n - 1; i++) {
		string compare_word; cin >> compare_word;

		if (isSimilar(main_word_alpha, main_word, compare_word)) {
			result++;
		}
	}

	cout << result;

	return 0;
}