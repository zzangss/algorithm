// boj 2447 별찍기 - 10

#include<iostream>
#define MAX 6565;

using namespace std;

bool arr[MAX][MAX] = {false,};

void solve(int n, int row, int col){
    if(n <= 1){
        arr[row][col] = true;
        return;
    }

    int nextn = n / 3;

    // 왼쪽줄
    solve(nextn, row, col);
    solve(nextn, row + nextn, col);
    solve(nextn, row + nextn*2, col);

    // 오른쪽 줄
    solve(nextn, row, col + nextn*2);
    solve(nextn, row + nextn, col + nextn*2);
    solve(nextn, row + nextn*2, col + nextn*2);

    // 가운데 위, 아래
    solve(nextn, row, col + nextn);
    solve(nextn, row + nextn*2, col + nextn);
}

int main(){
    //입력
    int n;
    cin >> n;

    //연산
    solve(n, 0, 0);

    //출력
    for(int i = 0; i<n; i++){
        for(int k = 0; k<n; k++){
            if(arr[i][k]){
                cout << "*";
            }
            else{
                cout << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}