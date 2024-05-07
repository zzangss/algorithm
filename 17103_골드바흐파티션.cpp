#include<iostream>
#include<vector>
#define MAX 1000000

using namespace std;

void prime(int check[]) {
	check[1] = 1;

	for (int i = 2; i * i <= MAX; i++) {
		if (check[i] == 1) continue;
		for (int k = i * i; k <= MAX; k += i) {
			check[k] = 1;
		}
	}

}

int main() {
	int t;
	cin >> t;

	int check[MAX+1] = { 0 };

	prime(check);
	
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int result = 0;
		for (int i = 2; i < MAX; i++) {
			vector<int>v(n, 0);
			int temp = n - i;
			if (i >= n) break;
			if (check[i] == 0 && check[temp] == 0) {
				if (v[i] == 0 && v[temp] == 0) {
					result++;
					v[i] = 1;
					v[temp] = 1;
				}

			}
		}
		cout << result;
	}
	
}