#include<iostream>
#include<stack>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	stack<int> s;

	for (int i = 0; i < n; i++) {
		int order; cin >> order;
		if (order == 1) {
			int order2; cin >> order2;
			s.push(order2);
		}
		else if (order == 2) {
			if (s.empty()) {
				cout << -1 << "\n";
			}
			else {
				cout << s.top() << "\n";
				s.pop();
			}
		}
		else if (order == 3) {
			cout << s.size() << "\n";
		}
		else if (order == 4) {
			if (s.empty()) cout << 1 << "\n";
			else cout << 0 << "\n";
		}
		else if (order == 5) {
			if (s.empty()) cout << -1 << "\n";
			else cout << s.top() << "\n";
		}
	}
}