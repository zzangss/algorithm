#include<iostream>
#include<vector>
#include<string>

using namespace std;

int add(int masking, int num) {
	int temp = 1;
	temp = temp << (num - 1);
	return masking | temp;
}

int remove(int masking, int num) {
	int temp = 1;
	temp = temp << (num - 1);
	return masking ^ temp;
}

bool check(int masking, int num) {
	int temp = 1;
	temp = temp << (num - 1);
	return masking & temp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n; cin >> n;

	int masking = 0;
	for (int i = 0; i < n; i++) {
		string cmd;
		cin >> cmd;

		int num;
		if (cmd.compare("add") == 0) {
			cin >> num;
			masking = add(masking, num);
		}
		else if (cmd.compare("remove") == 0) {
			cin >> num;
			if (check(masking, num)) {
				masking = remove(masking, num);
			}
		}
		else if (cmd.compare("check") == 0) {
			cin >> num;
			if (check(masking, num)) {
				cout << 1 << "\n";
			}
			else {
				cout << 0 << "\n";
			}
		}
		else if (cmd.compare("toggle") == 0) {
			cin >> num;
			if (check(masking, num)) {
				masking = remove(masking, num);
			}
			else {
				masking = add(masking, num);
			}
		}
		else if (cmd.compare("all") == 0) {
			int temp = ~masking;
			masking = masking ^ temp;
		}
		else if (cmd.compare("empty") == 0) {
			masking = 0;
		}
	}

	return 0;
}