#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	string temp = to_string(n);
	
	long long sum = 0;

	sum += (n - pow(10, temp.size() - 1) + 1)*temp.size();

	for (int i = 1; i < temp.size(); i++) {
		sum += (pow(10, i) - pow(10, i - 1))*i;
	}

	cout << sum;
	
}