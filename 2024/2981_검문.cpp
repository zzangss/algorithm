#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

//유클리드 호제법 이용해서 최대공약수 구하는 함수
int getGCD(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}
/*
int getGCD(int a, int b){
	if(b==0){
	return a;
	}
	return getGCD(b, a%b);
}
*/

vector<int> findM(int n, vector<int>& numbers) {
	vector<int> result;

	// 수들의 차의 최대 공약수 계산
	int gcd = numbers[1] - numbers[0];
	for (int i = 2; i < n; i++) {
		gcd = getGCD(gcd, numbers[i] - numbers[i - 1]);
	}

	//가능한 모든 m -> 최대공약수의 약수 찾기
	for (int i = 2; i * 2 <= gcd; i++) {
		if (gcd % i == 0) {
			result.push_back(i);
		}
	}
	result.push_back(gcd); //남은 gcd 넣기

	return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	//연산
	sort(v.begin(), v.end());
	vector<int> result = findM(n, v);

	//출력
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	return 0;
}