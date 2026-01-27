// boj 10994 별찍기 - 19

#include<iostream>
#include<vector>

using namespace std;

int arr[405][405] = {0,}; // 0 : 공백, 1 : *

void star(int num, int row, int col){
    // 기저 조건
    if(num == 1){
        arr[row][col] = 1; // 가장 가운데 부분 *로 표시하고 재귀 끝냄.
        return;
    }

    // * 표시
    int width = 1 + 4 * (num - 1) - 1;
    for(int i = 0; i <= width; i++){
        arr[row][col + i] = 1; // 윗변
        arr[row + i][col] = 1; // 왼쪽변
        arr[row + width][col + i] = 1; // 아랫변
        arr[row + i][col + width] = 1; // 오른쪽 변
    }

    // 다음 재귀 시작
    star(num - 1, row + 2, col + 2);
}

int main(){
    // 입력
    int n;
    cin >> n;

    // 연산
    star(n, 0, 0);

    // 출력
    int width = 1 + 4 * (n - 1);
    for(int i = 0; i < width; i++){
        for(int k = 0; k < width; k++){
            cout << arr[i][k];
        }
        cout << endl;
    }

    return 0;
}