#include<iostream>
#include<stack>
#include<vector>

using namespace std;

vector<int> solve(vector<int>& v) {
	stack<int> s;
	vector<int> result(v.size(), -1);
	//오큰수 조건을 만족하지 않는 경우엔 초기값을 수정하지 않음
	//초기값으로 -1 설정해놓으면 추가적으로 확인할 필요 x

	for (int i = 0; i < v.size(); i++) {
		while (!s.empty() && v[s.top()] < v[i]) {
			result[s.top()] = v[i];
			s.pop();
		}
		s.push(i);
	}

	return result;
}

int main() {
	int n; cin >> n;

	vector<int> v(n);
	vector<int> result;

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	result = solve(v);

	for (int i = 0; i < n; i++) {
		cout << result[i] << " ";
	}
}