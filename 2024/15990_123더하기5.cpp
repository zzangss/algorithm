#include<iostream>
#include<vector>
#define MAX 100000
#define MOD 1000000009

using namespace std;

int dp[100001][4];

void dP() {
	dp[1][1] = 1; //1
	dp[2][2] = 1; //2
	dp[3][1] = 1;
	dp[3][2] = 1;
	dp[3][3] = 1; //3

	for (int i = 4; i <= MAX; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % MOD;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % MOD;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % MOD;

	}
}

int main() {
	dP();

	int n;
	cin >> n;
	
	while (n--) {
		int temp;
		cin >> temp;
		cout << ((long long)dp[temp][1] + dp[temp][2] + dp[temp][3]) % MOD << "\n";
	}



	
}