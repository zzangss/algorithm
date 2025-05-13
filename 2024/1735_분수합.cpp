#include<iostream>
#include<algorithm>

using namespace std;

int GCD(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a1, b1, a2, b2;

	cin >> a1 >> b1;
	cin >> a2 >> b2;

	int numerator, denominator;

	numerator = a1 * b2 + b1 * a2;
	denominator = b1 * b2;

	int gcd = GCD(max(numerator, denominator), min(numerator, denominator));


	cout << numerator / gcd << " " << denominator / gcd;

	return 0;

}