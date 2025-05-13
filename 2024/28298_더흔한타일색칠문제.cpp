#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<string> v1 (k, "");
	vector<vector<string>> color(k, v1);
	vector<string> box(k, "");
	vector<int> alph(26, 0);
	int max = 0;
	int sum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c;
			cin >> c;
			color[i % k][j % k] += c; //ex. "ABVBAC" + c
		}
	}

	for (int i = 0; i < k; i++) {
		for (int j = 0; j < k; j++) {
			for (int p = 0; p < color[i][j].size(); p++) {
				alph[color[i][j][p] - 'A']++;
			}
			char c;
			for (int p = 0; p < 26; p++) {
				if (max < alph[p]) {
					max = alph[p];
					c = 'A' + p;
				}
			}
			for (int p = 0; p < 26; p++) {
				alph[p] = 0;
			}
			sum += max;
			max = 0;
			box[i] += c;
		}
	}

	//결과 출력
	cout << n*m - sum << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << box[i % k][j % k];
		}
		cout << "\n";
	}
	

}