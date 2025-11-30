// BOJ 7795 - 먹을 것인가 먹힐 것인가

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve(vector<int>& A, vector<int>& B, int n, int m) {
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	int cumulate_sum = 0;

	int k = 0, i;
	for (i = 0; i < n; i++) {
		while(k < m) {
			if (A[i] > B[k]) {
				k++;
			}
			else {
				break;
			}
		}
		cumulate_sum += k;
	}

	return cumulate_sum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t, n, m;
	cin >> t;

	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		vector<int> A(n);
		vector<int> B(m);
		for (int j = 0; j < n; j++) {
			cin >> A[j];
		}
		for (int k = 0; k < m; k++) {
			cin >> B[k];
		}

		cout << solve(A, B, n, m) << "\n";
	}
}