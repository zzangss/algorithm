#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> v(n + 1, 0);
	vector<int> check(n + 1, 1);
	vector<string> result(n + 1, "");

	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}

	int max = 0;
	int resultlocation = 0;
	for (int i = 1; i <= n; i++) {
		int maxlocation = 0;
		check[i] = 1;
		result[i] = "";
		for (int j = i - 1; j >= 1; j--) {
			if (v[i] > v[j] && check[j] >= check[i]) {
				check[i] = check[j] + 1;
				maxlocation = j;
			}
		}
		if (max < check[i]) { 
			max = check[i];
			resultlocation = i;
		}
		if (result[maxlocation].empty()) {
			result[i] += to_string(v[i]);
		}
		else {
			result[i] += (result[maxlocation] + " " + to_string(v[i]));
		}
	}

	cout << max << "\n";
	cout << result[resultlocation];
}