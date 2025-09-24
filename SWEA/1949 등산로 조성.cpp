/*
  접근 방법 및 구현
  - 지도에서 가장 높은 높이를 저장
  - 해당 지점이 가장 높을 경우 조건에 따라 이동
  - DFS로 등산로 길이 탐색
  - 현재 위치보다 낮은 곳으로 이동이 가능할 시 최대값 갱신
  - 이동이 불가능하지만 아직 공사를 하지 않았고 현재 위치보다 낮게 만들 수 있다면 공사 후 이동
  - 다른 경로 탐색을 위해 백트래킹 수행(방문 해제)
*/

#include<iostream>
#include<algorithm>
using namespace std;
int n, k, res;
int map[9][9];
bool check[9][9];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};
int dfs(int y, int x, int height, bool digged) {
    check[y][x] = true;
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        // 범위 내 미방문
        if (nx >= 0 && ny >= 0 && nx < n && ny < n && !check[ny][nx]) {
            // 현재 위치보다 낮은 코드로 이동 시
            if (map[ny][nx] < height) {
                cnt = max(cnt, dfs(ny, nx, map[ny][nx], digged));
            } else {
                // 공사를 하지 않았고 낮게 만들 수 있는 경우
                if (!digged && map[ny][nx]-k < height) {
                    cnt = max(cnt, dfs(ny, nx, height-1, true));
// cout << "map[" << ny << "][" << nx << "]-" << k << " = " << map[ny][nx]-k << endl;
                }
            }
        }
    }
    // 방문 해제
    check[y][x] = false;
// cout << "cnt: " << cnt+1 << endl;
    return cnt+1;
}
int main(int argc, char** argv)
{
	int T;
	cin>>T;
	for(int tc = 1; tc <= T; ++tc)
	{
		cin >> n >> k;
		res = 0;
        int max_val = -1;
		for (int i = 0; i < n; i++) {
		    for (int j = 0; j < n; j++) {
		        cin >> map[i][j];
		        check[i][j] = false;
		        max_val = max(max_val, map[i][j]);
		    }
		}
		for (int i = 0; i < n; i++) {
		    for (int j = 0; j < n; j++) {
		        if (max_val == map[i][j]) {
		            int tmp = dfs(i, j, map[i][j], false);
		            res = max(res, tmp);
		        }
		    }
		}
		cout << '#' << tc << ' ' << res << endl;
	}
	return 0;
}