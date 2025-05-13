#include<iostream>

using namespace std;

int bomboni(char arr[51][51], int max_num, int n) {

	
	for (int i = 0; i < n; i++) { 
		int temp_row = 1;
		int temp_col = 1;
		for (int j = 0; j < n - 1; j++) {
			if (arr[i][j] == arr[i][j + 1]) {
				temp_row++;
			}
			else {
				if (temp_row > max_num)max_num = temp_row;
				temp_row = 1;
			}

			if (arr[j][i] == arr[j + 1][i]) {
				temp_col++;
			}
			else {
				if (temp_col > max_num) max_num = temp_col;
				temp_col = 1;
			}
		}
		max_num = max(max_num, max(temp_col, temp_row));
	}

	return max_num;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n; cin >> n;

	char arr[51][51];

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			cin >> arr[i][k];
		}
	}
	int max_num = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n - 1; k++) {
			swap(arr[i][k], arr[i][k + 1]); //행바꿈
			max_num = max(max_num, bomboni(arr, max_num, n));
			swap(arr[i][k], arr[i][k + 1]); //원래대로

			swap(arr[k][i], arr[k + 1][i]);
			max_num = max(max_num, bomboni(arr, max_num, n));
			swap(arr[k][i], arr[k + 1][i]);
		}
	}

	cout << max_num;

}