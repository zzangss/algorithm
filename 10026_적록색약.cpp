#include<iostream>
#include<vector>
#include<memory.h>
#include<string>

using namespace std;

int n, cnt = 0;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1}; //상하좌우 움직이기 위한 배열
vector<string>rgb; //띄어쓰기 없이 받기 때문에 string 자료형 사용

vector<int>v;
vector<vector <int>> check; // 2차원 벡터


void DFS(int nowx, int nowy) {
	check[nowx][nowy] = 1;

	for (int i = 0; i < 4; i++) {
		int X = nowx + dx[i];
		int Y = nowy + dy[i]; //다음으로 방문할 위치의 x,y값

		if (X < 0 || X >= n || Y < 0 || Y >= n) continue; 
		//사각형 테두리 범위 넘어가지 않도록 조정
		
		if (check[X][Y] == 0 && rgb[X][Y] == rgb[nowx][nowy]) {
		//(방문하지 않음 && 현재 위치에서의 값 = 다음 위치에서의 값) 이면 DFS 수행
			DFS(X, Y);
		}
	}
}
int main() {
	cin >> n;

	v.resize(n, 0);
	rgb.resize(n);
	check.resize(n, v);	

	for (int i = 0; i < n; i++) {
		cin >> rgb[i]; //기본 rgb sheet 입력. 
	} 

	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (check[i][k] == 0) { //방문하지 않은 위치만
				DFS(i, k);
				cnt++; 
				//한 칸 방문이 끝나면 +1
			}
		}
	}

	cout << cnt << " ";


	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) { // 적록색약 rgb sheet 입력
			if (rgb[i][k] == 'G') {
				rgb[i][k] = 'R';
			}
		}
	}

	check.clear();
	check.resize(n, v); //원소 0으로 초기화
	cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			if (check[i][k] == 0) {
				DFS(i, k);
				cnt++;
			}
		}
	}

	cout << cnt;



}