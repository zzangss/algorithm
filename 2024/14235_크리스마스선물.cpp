#include<iostream>
#include<queue>

using namespace std;

void replenishPresent(int num_of_present, priority_queue<int> &present) {
	for (int i = 0; i < num_of_present; i++) {
		int n; cin >> n;
		present.push(n);
	}
}

int givePresent(priority_queue<int>& present) {
	int result = 0;
	if (present.empty()) {
		result = -1;
	}
	else {
		result = present.top();
		present.pop();
	}

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;

	priority_queue<int> present;

	for (int i = 0; i < n; i++) {
		int order; cin >> order;

		if (order == 0) {
			cout << givePresent(present) << "\n";
		}
		else {
			replenishPresent(order, present);
		}
	}
	
	return 0;
}