#include<iostream>
#include<vector>

using namespace std;

int CCW(pair<int,int> a, pair<int,int> b, pair<int,int> c ) {
	int n = (b.first - a.first) * (c.second - a.second) - (b.second - a.second) * (c.first - a.first);

	if (n < 0) return -1;
	else if (n > 0) return 1;
	else return 0;
}

int main() {
	vector<pair<int, int>> v(2);

	pair<int, int> a, b, c, d;
	cin >> a.first >> a.second >> b.first >> b.second;
	cin >> c.first >> c.second >> d.first >> d.second;


	if (CCW(a,b, c) * CCW(a,b,d) < 0) cout << 1;
	else cout << 0;
}