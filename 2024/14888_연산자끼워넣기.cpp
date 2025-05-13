#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 1000000000
#define MIN -1000000000
using namespace std;

vector<int> A;
vector<int> op; // (+,-,*,/)
int max_r = MIN, min_r = MAX;

int calc(int op, int a, int b) {
	int result = 0;
	switch (op) {
	case 1 :
		result = a + b;
		break;
	case 2:
		result = a - b;
		break;
	case 3:
		result = a * b;
		break;
	case 4:
		if (a < 0) {
			result = (abs(a) / b) * -1;
		}
		else {
			result = a / b;
		}
	}
	return result;
}

void backtracking(int sum, int depth) {
	if (depth == A.size()) {
		max_r = max(max_r, sum);
		min_r = min(min_r, sum);
		return;
	}

	for (int k = 0; k < 4; k++) {
		if (op[k] > 0) {
			int temp = sum;
			op[k]--;
			sum = calc(k + 1, temp, A[depth]);
			backtracking(sum, depth + 1);
			op[k]++;
			sum = temp;
		}
	}
}

int main() {
	int n; cin >> n;
	
	A.resize(n,0);
	op.resize(4, 0);

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}

	backtracking(A[0], 1);

	cout << max_r << "\n";
	cout << min_r << "\n";

	return 0;
}