#include<iostream>
#include<vector>

using namespace std;

bool check(vector<int>& v, int n, int h) {
	//위치 0부터 첫 가로등 사이의 거리, 위치 n부터 마지막 가로등 사이의 거리가
	//h 값보다 크면 가로등이 길을 다 밝혀주지 못함.
	if (v[0] - 0 > h || n - v[v.size() - 1] > h) {
		return false;
	}
	//가로등 사이사이 확인해보기
	//양쪽에서 밝혀주니, 거리가 가로등 높이의 1/2 이하면 길을 모두 밝힐 수 있음.
	for (int i = 0; i < v.size() - 1; i++) {
		if (v[i + 1] - v[i] > h * 2) {
			return false;
		}
	}
	return true;
}

int solve(vector<int>& v, int n) {
	int s = 0, e = n, m;
	int result = n;

	while (s <= e) {
		m = (s + e) / 2;

		if (check(v, n, m)) {
			result = m;
			e = m - 1; //현재까지는 불을 다 밝힐 수 있음. 그러니 가로등 높이를 더 줄여보기.
		}
		else {
			s = m + 1; //불을 다 밝힐 수 없으니 가로등 높이 올리기
		}
	}
	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m; cin >> n >> m;
	vector<int> v(m);
	for (int i = 0; i < m; i++) {
		cin >> v[i];
	}

	cout << solve(v, n);
}