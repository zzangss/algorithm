#include<iostream>
#include<string>

using namespace std;

int main() {
	
	string arr;
	cin >> arr;

	while (arr.size() % 3 != 0) {
		arr = '0' + arr;
	}

	for (int i = 0; i < arr.size(); i += 3) {
		int a = (arr[i] - '0') * 4 + (arr[i + 1] - '0') * 2 + (arr[i + 2] - '0');
		cout << a;
	}

}