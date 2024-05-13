#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n, d, k, c;

	cin >> n >> d >> k >> c;

	vector<int>v(n); //밸트 위 초밥들 입력
	vector<int>check(d + 1, 0); //어떤 종류의 초밥을 선택했는지 확인.

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int s = 0;
	int e = k - 1; //1~k 슬라이싱

	int kind = 0, MAX = 0;

	check[c]++;
	kind++;

	for (int i = 0; i < k; i++) {
		check[v[i]]++;
		if (check[v[i]] == 1) {
			kind++;
		}
	}

	MAX = kind;

	while (s<n) {

		check[v[s]]--;
		if (check[v[s]] == 0) {
			kind--;
		}
		s++;

		if (e < n - 1) {
			e++;
		}
		else {
			e = 0;
		}
		check[v[e]]++;
		if (check[v[e]] == 1) {
			kind++;
		}

		if (check[c] == 0) {
			MAX = max(MAX, kind + 1);
		}
		else {
			MAX = max(MAX, kind);
		}

	}

	cout << MAX;

	return 0;
}