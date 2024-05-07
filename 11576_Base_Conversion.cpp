#include<iostream>
#include<vector>

using namespace std;

int aToTen(vector<int> v, int a) {

	int tmp = 1;
	int result = 0;
	for (int i = v.size()-1; i >= 0; i--) {
		result += v[i] * tmp;
		tmp *= a;
	}

	return result;
}

vector<int> tenToB(int ten, int b) {
	vector<int> tmp;
	vector<int>result;

	int 몫 = ten;
	int 나머지 = 0;
	while (true) {
		if (몫 < b) {
			break;
		}
		나머지 = 몫 % b;
		몫 /= b;

		tmp.push_back(나머지);
	}
	tmp.push_back(몫);

	for (int i = tmp.size() - 1; i >= 0; i--) {
		result.push_back(tmp[i]);
	}

	return result;
}

int main() {
	int a, b, num;
	cin >> a >> b;
	cin >> num;

	vector<int> v(num,0);

	for (int i = 0; i < num; i++) {
		int tmp;
		cin >> tmp;
		v[i] = tmp;
	}

	int ten = 0;

	ten = aToTen(v, a);
	
	vector<int>result;

	result = tenToB(ten, b);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

}