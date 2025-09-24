/*
  접근 방법 및 구현
  - 현재 파이프의 방향과 연결 가능한 파이프를 확인해야 함
  - 다음 파이프로 이동 가능할 시 확장
  - 다음 칸으로 이동 가능한지 체크하는 함수를 정의
  - 최소 거리를 찾는 문제로 간주 가능하므로 BFS 사용
  - 종료 후 l시간 이내 도달 가능한 칸 수를 계산
*/

#include<iostream>
#include<cstring>
#include<queue>
#define endl '\n'
using namespace std;
int n, m, r, c, l, ans;
int map[51][51];
int visit[51][51];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};
bool check(int dir, int next) {
    // 상: 하로서 연결되는 1/2/5/6
    if (dir == 0) {
        if (next == 1 || next == 2 || next == 5 || next == 6) {
            return true;
        }
    // 좌: 우로서 연결되는 1/3/4/5
    } else if (dir == 1) {
        if (next == 1 || next == 3 || next == 4 || next == 5) {
            return true;
        }
    // 하: 상으로서 연결되는 1/2/4/7
    } else if (dir == 2) {
        if (next == 1 || next == 2 || next == 4 || next == 7) {
            return true;
        }
    // 우: 좌로서 연결되는 1/3/6/7
    } else if (dir == 3) {
        if (next == 1 || next == 3 || next == 6 || next == 7) {
            return true;
        }
    }
    return false;
}
void bfs() {
    queue<pair<int, int>> q;
    q.push({r, c});
    visit[r][c] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int cur = map[x][y];
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = x + dr[i];
            int nc = y + dc[i];
            // map을 벗어날 시 패스
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (visit[nr][nc] == 0) {
                int next = map[nr][nc];
// cout << "next(visit[" << nr << "][" << nc << "]): " << next << endl;
                // 상하좌우: 조건 없음
                if (cur == 1) {
                    if (check(i, map[nr][nc])) {
                        visit[nr][nc] = visit[x][y] + 1;
                        q.push({nr, nc});
                    }
                // 상하: 하 또는 상일 시
                } else if (cur == 2) {
                    if (i == 0 || i == 2) {
                        if (check(i, next)) {
                            visit[nr][nc] = visit[x][y] + 1;
                            q.push({nr, nc});
                        }
                    }
                // 좌우: 우 또는 좌일 시
                } else if (cur == 3) {
                    if (i == 1 || i == 3) {
                        if (check(i, next)) {
                            visit[nr][nc] = visit[x][y] + 1;
                            q.push({nr, nc});
                        }
                    }
                // 상우: 하 또는 좌일 시
                } else if (cur == 4) {
                    if (i == 0 || i == 3) {
                        if (check(i, next)) {
                            visit[nr][nc] = visit[x][y] + 1;
                            q.push({nr, nc});
                        }
                    }
                // 하우: 상 또는 좌일 시
                } else if (cur == 5) {
                    if (i == 3 || i == 2) {
                        if (check(i, next)) {
                            visit[nr][nc] = visit[x][y] + 1;
                            q.push({nr, nc});
                        }
                    }
                // 하좌: 상 또는 우일 시
                } else if (cur == 6) {
                    if (i == 1 || i == 2) {
                        if (check(i, next)) {
                            visit[nr][nc] = visit[x][y] + 1;
                            q.push({nr, nc});
                        }
                    }
                // 상좌: 하 또는 우일 시
                } else if (cur == 7) {
                    if (i == 1 || i == 0) {
                        if (check(i, next)) {
                            visit[nr][nc] = visit[x][y] + 1;
                            q.push({nr, nc});
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // 주어진 시간 동안 방문하였을 시
            if (visit[i][j] != 0 && visit[i][j] <= l) {
                ans++;
            }
// cout << "visit[" << i << "][" << j << "]: " << visit[i][j] << endl;
        }
    }
}
int main(int argc, char** argv)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int T;
	cin>>T;
	for(int tc = 1; tc <= T; ++tc)
	{
	    ans = 0;
		cin >> n >> m >> r >> c >> l;
		for (int i = 0; i < n; i++) {
		    for (int j = 0; j < m; j++) {
		        cin >> map[i][j];
		    }
		}
		memset(visit, 0, sizeof(visit));
		bfs();
		cout << '#' << tc << ' ' << ans << endl;
	}
	return 0;
}