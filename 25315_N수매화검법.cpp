#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define ll long long

using namespace std;

int CCW(pair<ll, ll> a, pair<ll, ll> b, pair<ll, ll> c) {
	ll n = (b.first - a.first)*(c.second - a.second) - (b.second - a.second) * (c.first - a.first);
	if (n < 0) return 1;
	else if (n > 0) return -1;
	else return 0;
}

int main() {
	int n;
	cin >> n;

	vector <ll> v(5,0);
	vector<vector<ll>> xy(n, v);
	ll result = 0;

	for (int i = 0; i < n; i++) {
		cin >> xy[i][1] >> xy[i][2];
		cin >> xy[i][3] >> xy[i][4];
		cin >> xy[i][0];
	}

	sort(xy.begin(), xy.end());

	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int k = i+1; k < n; k++) {
			int line1 = CCW({ xy[i][1], xy[i][2] }, { xy[i][3], xy[i][4] }, { xy[k][1], xy[k][2] }) * CCW({ xy[i][1], xy[i][2] }, { xy[i][3], xy[i][4] }, { xy[k][3], xy[k][4] });
			int line2 = CCW({ xy[k][1], xy[k][2] }, { xy[k][3], xy[k][4] }, { xy[i][1], xy[i][2] }) * CCW({ xy[k][1], xy[k][2] }, { xy[k][3], xy[k][4] }, { xy[i][3], xy[i][4] });


			if (line1 < 0 && line2 < 0) {
				cnt++;
			}
		}
		result += xy[i][0] * (cnt + 1);
	}
	
	cout << result;

}