#include<iostream>
#include<vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//입력
	int n; cin >> n;
	vector<int> planet(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> planet[i]; // 행성 간격 입력
	}

	//연산
	long long result = 0; // 지구에서의 최소 출발속도 (결과)
	for (int i = n - 1; i >= 0; i--) { 
		//n번째 행성부터 1번째 행성까지 거꾸로 확인한다. 
		// 1. 만약 현재까지 저장된 result 값보다 앞 행성의 간격이 길면 result를 앞 행성 간격으로 업데이트. 
		// 2. 현재까지 저장된 result값보다 앞 행성 간격이 짧은 경우
		// 2-1.(result가 앞 행성 간격의 배수이면) 바꾸지 않아도 된다.
		// 2-2.(result가 앞 행성 간격의 배수가 아니면)result보다 큰 앞 행성값의 배수를 입력한다.
		if (result < planet[i]) { 
			result = planet[i];
		}
		else if(result > planet[i]) {
			if (result % planet[i] != 0) {
				result = (result / planet[i] + 1) * planet[i];
			}
		}
	}

	// 출력
	cout << result;

	return 0;
}