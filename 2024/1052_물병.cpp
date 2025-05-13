#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int calMasking(int masking, int k, int cnt){
	int temp = 1, temp_two = 1;
	int forenum = 0;
	int result = 0;
	while (cnt > k && masking >= temp) {
		if ((masking & temp) != 0) {
			if (forenum != 0) {
				result += temp - forenum;
				temp *= 2;
				while ((masking & (temp)) > 0) {
					temp *= 2;
					cnt--;
				}
				masking = masking | (temp);
				forenum = temp;
				cnt--;
			}
			else {
				forenum = temp;
				temp_two *= 2;
			}
		}
		temp *= 2;
	}

	return result;
	
}

int bottle(int n, int k) {
	int temp = 1, cnt = 0;
	int masking = n;
	while(masking){
		if (masking % 2 == 1) {
			cnt++;
		}
		masking /= 2;
	}

	if (cnt <= k) {
		return 0;
	}
	else {
		return calMasking(n, k, cnt);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;

	cout << bottle(n, k);

	return 0;
}