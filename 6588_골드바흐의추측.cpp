#include<iostream>
#include<vector>
#include<math.h>
#define NumOfPrime 1000000

using namespace std;

vector<bool> primeNum(NumOfPrime + 1, false);

void prime() {
	primeNum[0] = true;
	primeNum[1] = true;
	for (int i = 2; i <= sqrt(NumOfPrime); i++) {
		for (int k = i * i; k <= NumOfPrime; k += i) {
			if (primeNum[k]) continue;
			primeNum[k] = true;
		}
	}
}

void goldbach(int n) {
	for (int i = 3; i <= n; i++) {
		if (primeNum[i] == false && primeNum[n - i] == false) {
			printf("%d = %d + %d\n", n, i, n - i);
			return;
		}
	}
	cout << "Goldbach's conjecture is wrong.\n";
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	prime();

	while (true) {
		int n; cin >> n;
		if (n == 0) break;
		goldbach(n);
	}

	return 0;
}