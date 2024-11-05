#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, m, max_safe = 0;
vector<vector<int>>map;
vector<vector<int>>temp;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

bool range(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void copyMap(vector<vector<int>>temp, vector<vector<int>>map) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            temp[i][j] = map[i][j];
        }
    }
}

int cntSafe() {
    int result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 0 && check[i][j] == false) {
                result++;
            }
        }
    }
    return result;
}

void BFS(int x, int y)
{
    vector<vector<int>>birus(n, vector<int>(m, 0));
    copyMap(birus, temp);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == 2) {
                for (int k = 0; k < 4; k++)
                {
                    int nx = x + dx[k];
                    int ny = y + dy[k];

                    if (range(nx, ny) && !check[nx][ny] && map[nx][ny] == 0)
                    {
                        check[nx][ny] = true;
                        BFS(nx,ny);
                    }
                }
            }
        }
    }
}

void makeWall(int n) {
    if (n == 3) {
        BFS();
        return;
    }
    //벽을 세움
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (temp[i][j] == 0) {
                temp[i][j] = 1;
                makeWall(n + 1);
                temp[i][j] = 0;
            }
        }
    }
}

int main() {
	cin >> n >> m;

	map.assign(n, vector<int>(m, 0));
    map.assign(n, vector<int>(m, 0));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}

    
    makeWall(0);

}