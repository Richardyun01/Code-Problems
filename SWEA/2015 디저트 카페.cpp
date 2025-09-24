/*
  접근 방법 및 구현
  - 대각선으로 좌표를 이동하도록 DFS를 구현
  - 노드에서 사용되었던 숫자를 사용하지 않으면서 출발 지점으로 되돌아가는데 필요한 이동 횟수를 계산
  - 시작지점 고려: 이미 사용한 숫자여도 그 지점이 시작 지점이면 함수 진입을 허용해야 함(시작 지점은 방문 처리 X)
  - 시작점으로 바로 돌아오지 않도록 방지
*/

#include<iostream>
#include<vector>
#define endl '\n'
using namespace std;
typedef pair<int, int> pii;
pii src;
const int dr[4] = {1, 1, -1, -1};
const int dc[4] = {1, -1, -1, 1};
int n, map[21][21];
bool vis[21][21], used[101];
int max_val = -1;
void dfs(pii cur, int dir, int cnt) {
    // 시작점으로 돌아왔을 때 최대값 갱신/바로 돌아오는 경우 방지
    if (cur.first == src.first && cur.second == src.second && cnt > 1) {
        if (max_val < cnt) max_val = cnt;
        return;
    }
    // 직진하거나 꺾음
    for (int i = 0; i < 2; i++) {
        // 사각형은 4번까지만 회전 가능
        if (dir+i >= 4) break;
        int nr = cur.first + dr[dir+i];
        int nc = cur.second + dc[dir+i];
        if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
        // 아직 방문하지 않았고 같은 디저트를 먹지 않았을 경우
        if (!vis[nr][nc] && !used[map[nr][nc]]) {
            // 해당 디저트 먹음
            used[map[nr][nc]] = true;
// cout << "dfs map[" << nr << "][" << nc << "]: " << map[nr][nc] << endl;
            dfs({nr, nc}, dir+i, cnt+1);
            // 방문 해제, 사용 해제
            vis[nr][nc] = false;
            used[map[nr][nc]] = false;
        // 시작 지점으로 돌아올 수 있는 경우
        } else if (nr == src.first && nc == src.second) {
            dfs({nr, nc}, dir+i, cnt+1);
        }
    }
}
int main(int argc, char** argv)
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int T;
	cin>>T;
	for(int tc = 1; tc <= T; ++tc)
	{
		cin >> n;
		for (int i = 0; i < n; i++) {
		    for (int j = 0; j < n; j++) {
		        cin >> map[i][j];
		    }
		}
		for (int i = 0; i < n-1; i++) {
		    for (int j = 0; j < n-1; j++) {
		        src.first = i;
		        src.second = j;
		        used[map[i][j]] = true;
// cout << "current map[" << i << "][" << j << "]: " << map[i][j] << endl;
		        dfs({i, j}, 0, 0);
		        used[map[i][j]] = false;
		    }
		}
		cout << '#' << tc << ' ' << max_val << endl;
		max_val = -1;
	}
	return 0;
}