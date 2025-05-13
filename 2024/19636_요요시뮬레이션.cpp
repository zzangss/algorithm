#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main() {
	int weight, l0, t;
	int day, eat, active;

	cin >> weight >>  l0 >> t;
	cin >> day >> eat >> active;

	int result_weight1 = weight, result_weight2 = weight;
	int result1 = l0, result2 = l0;
	for (int i = 0; i < day; i++) {
		int temp1 = eat - (active + result1);
		int temp2 = eat - (active + result2);
		if (abs(temp2) > t) {
			if (temp2 % 2 != 0) {
				result2 += temp2 / 2 - 1;
			}
			else {
				result2 += temp2 / 2;
			}
		}
		result_weight1 += temp1;
		result_weight2 += temp2;
	}

	if (result_weight1 <= 0 || result1 <= 0) {
		cout << "Danger Diet" << endl;
	}
	else {
		cout << result_weight1 << " " << result1 << endl;
	}

	if (result_weight2 <= 0 || result2 <= 0) {
		cout << "Danger Diet" << endl;
	}
	else {
		cout << result_weight2 << " " << result2;
		if (l0 - result2 > 0) cout << " YOYO";
		else cout << " NO";
	}

	return 0;
}