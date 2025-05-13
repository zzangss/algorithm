#include<iostream>

using namespace std;

int gcd(int first, int second) {
	if (second == 0) { return first; }
	else { return gcd(second, first % second); }
}

int main() {
	int n, s;
	cin >> n >> s;

	int temp = 0;
	cin >> temp;
	temp = abs(temp - s);

	for (int i = 1; i < n; i++) {
		int location = 0;
		cin >> location;
		location = abs(location - s);
		if (location < temp) {
			swap(location, temp);
		}
		temp = gcd(location, temp);
	}

	cout << temp;
}