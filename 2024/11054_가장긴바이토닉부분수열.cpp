#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	vector<int> v(n);
	vector<int> dp1(n);
	vector<int> dp2(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	dp1[0] = 1;
	for (int i = 1; i < n; i++) {
		dp1[i] = 1;
		for (int j = i - 1; j >= 0; j--) {
			if (v[i] > v[j] && dp1[i] < dp1[j] + 1) {
				dp1[i] = dp1[j] + 1;
			}
		}
	}

	dp2[n-1] = 1;
	for(int i = n - 2; i >= 0; i--){
		dp2[i] = 1;
		for (int j = i + 1; j < n; j++) {
			if (v[i] > v[j] && dp2[i] < dp2[j] + 1) {
				dp2[i] = dp2[j] + 1;
			}
		}
	}

	int result = 0;

	for (int i = 0; i < n; i++) {
		result = max(result, dp1[i] + dp2[i] - 1);
	}

	cout << result;
}