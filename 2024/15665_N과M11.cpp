#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> num_arr;
vector<int> sequence;


void makeNumArr(vector<int>& input) {
	sort(input.begin(), input.end());
	for (int i = 0; i < input.size(); i++) {
		if (!num_arr.empty() && num_arr.back() == input[i]) {
			continue;
		}
		num_arr.push_back(input[i]);
	}
}

void printSeq() {
	for (int i = 0; i < sequence.size(); i++) {
		cout << sequence[i] << " ";
	}
	cout << "\n";
}

void backtracking(int m, int depth) {
	if (m == depth) {
		printSeq();
		return;
	}

	for (int num : num_arr) {
		sequence[depth] = num;
		backtracking(m, depth + 1);
	}
}

int main() {

	//입력
	int n, m;
	cin >> n >> m;

	vector<int> input(n);

	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}

	//연산
	sequence.resize(m, 0);
	makeNumArr(input);
	backtracking(m, 0);

	return 0;
}