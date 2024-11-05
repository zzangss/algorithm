#include<iostream>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//ют╥б
	int n, m; cin >> n >> m;

	int num = 0, temp = 0; 
	int result = -1;
	for (int i = 0; i < m; i++) {
		cin >> num;
		if (i == 0) {
			result = max(result, num - 0);
		}
		if (i == m - 1) {
			result = max(result, n - num);
		}
		if ((num - temp) % 2 == 1) {

		}
		result = max(result, (int)ceil((double)(num - temp) / 2));
		temp = num;
	}

	cout << result;
}