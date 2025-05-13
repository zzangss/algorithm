#include<iostream>
#include<vector>
#include<stack>
#include<math.h>

using namespace std;

stack <int> tenToB(int ten, int b) {
	stack<int> result;

	int tmp = ten;
	while (tmp) {
		result.push(tmp % b);
		tmp /= b;
	}

	return result;
}

int main() {
	int a, b, num;
	cin >> a >> b;
	cin >> num;

	int ten = 0;


	while(num--) {
		int tmp;
		cin >> tmp;
		ten += tmp * pow(a, num);
	}
	//입력과 동시에 10진수로 변환 가능하다.
	//다른 진법 변환 문제와 달리 10 이상의 숫자가
	//정수 그대로 표현되기 때문이다.
	
	stack<int>result;

	result = tenToB(ten, b);
	int size = result.size();
	for (int i = 0; i < size; i++) {
		cout << result.top() << " ";
		result.pop();
	}

}