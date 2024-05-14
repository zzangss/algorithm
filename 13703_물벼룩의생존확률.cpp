#include<iostream>
#include<vector>

using namespace std;

vector<long long>v(100, -1);
vector<vector<long long>>check(1000, v); 
//자료형 조심. longlong
//범위도 제시된 문제에 맞게 넉넉히 잡기

long long dP(long long cm, long long time) {
	if (cm == 0) {
		return 0; //물벼룩이 잡아먹히는 경우를 세지 않는다.
	}
	if (time == 0) {
		return 1; //기저 설정.
	}
	if (check[cm][time] != -1) {
		return check[cm][time]; 
		//이미 dp로 확인한 경우엔 그대로 리턴한다.
		//0 or 1 이 입력되어 있을 것이다.
	}
	
	check[cm][time] = dP(cm + 1, time - 1) + dP(cm - 1, time - 1);
	return check[cm][time];
}

int main() {
	int k, n;
	cin >> k >> n;

	long long result = dP(k, n); 
	//int 자료형 범위를 넘어가기 때문에 long long으로
	cout << result;

	return 0;

}