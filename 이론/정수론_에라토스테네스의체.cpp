#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

vector<bool> findPrime(int n) {
	vector<bool> is_prime(n + 1, true);

	for (int i = 2; i * i <= n; i++) {
		if (is_prime[k]) {
			for (int k = i * i; k <= n; k += i) {
				is_prime[k] = false;
			}
		}
	}

	return is_prime;
}

int main() {
	int n; cin >> n;

	vector<bool> is_prime= findPrime(n);

	for (int i = 2; i <= n; i++) {
		if (is_prime[i]) cout << i << " ";
	}

	return 0;
}
