#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, result = 0;
	cin >> n;

	vector<pair<int, int>> time(n, { 0,0 });

	for (int i = 0; i < n; i++) {
		cin >> time[i].second >> time[i].first;
	}

	//연산
	sort(time.begin(), time.end());

	int finish_time = 0;
	for (int i = 0; i < n; i++) {
		if (time[i].second >= finish_time) {
			finish_time = time[i].first;
			result++;
		}
	}

	//출력
	cout << result;
	
	return 0;
}