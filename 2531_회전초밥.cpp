#include<iostream>
#include<vector>

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

	int kind = 0;
	int max = 0;
	int checkC = 0;

	for (int i = 0; i < k; i++) {
		check[v[i]]++;
		if (v[i] == c) {
			checkC++;
		}
		if (check[v[i]] == 1) {
			kind++;
		}

	}

	max = kind;

	while (true) {
		if (s >= n - 1) {
			break;
		}
		if (kind >= n + 1) {
			break;
		}

		check[v[s]]--;
		if (check[v[s]] == 0) {
			kind--;
		}
		if (v[s] == c) {
			checkC--;
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
		if (v[e] == c) {
			checkC++;
		}


		if (checkC >= 1) {
			if (max < kind) {
				max = kind;
			}
		}
		else {
			if (max < kind + 1) {
				max = kind + 1;
			}
		}

	}

	cout << max;

	return 0;
}