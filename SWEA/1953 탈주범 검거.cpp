/*
  ���� ��� �� ����
  - ���� �������� ����� ���� ������ �������� Ȯ���ؾ� ��
  - ���� �������� �̵� ������ �� Ȯ��
  - ���� ĭ���� �̵� �������� üũ�ϴ� �Լ��� ����
  - �ּ� �Ÿ��� ã�� ������ ���� �����ϹǷ� BFS ���
  - ���� �� l�ð� �̳� ���� ������ ĭ ���� ���
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
    // ��: �Ϸμ� ����Ǵ� 1/2/5/6
    if (dir == 0) {
        if (next == 1 || next == 2 || next == 5 || next == 6) {
            return true;
        }
    // ��: ��μ� ����Ǵ� 1/3/4/5
    } else if (dir == 1) {
        if (next == 1 || next == 3 || next == 4 || next == 5) {
            return true;
        }
    // ��: �����μ� ����Ǵ� 1/2/4/7
    } else if (dir == 2) {
        if (next == 1 || next == 2 || next == 4 || next == 7) {
            return true;
        }
    // ��: �·μ� ����Ǵ� 1/3/6/7
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
            // map�� ��� �� �н�
            if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
            if (visit[nr][nc] == 0) {
                int next = map[nr][nc];
// cout << "next(visit[" << nr << "][" << nc << "]): " << next << endl;
                // �����¿�: ���� ����
                if (cur == 1) {
                    if (check(i, map[nr][nc])) {
                        visit[nr][nc] = visit[x][y] + 1;
                        q.push({nr, nc});
                    }
                // ����: �� �Ǵ� ���� ��
                } else if (cur == 2) {
                    if (i == 0 || i == 2) {
                        if (check(i, next)) {
                            visit[nr][nc] = visit[x][y] + 1;
                            q.push({nr, nc});
                        }
                    }
                // �¿�: �� �Ǵ� ���� ��
                } else if (cur == 3) {
                    if (i == 1 || i == 3) {
                        if (check(i, next)) {
                            visit[nr][nc] = visit[x][y] + 1;
                            q.push({nr, nc});
                        }
                    }
                // ���: �� �Ǵ� ���� ��
                } else if (cur == 4) {
                    if (i == 0 || i == 3) {
                        if (check(i, next)) {
                            visit[nr][nc] = visit[x][y] + 1;
                            q.push({nr, nc});
                        }
                    }
                // �Ͽ�: �� �Ǵ� ���� ��
                } else if (cur == 5) {
                    if (i == 3 || i == 2) {
                        if (check(i, next)) {
                            visit[nr][nc] = visit[x][y] + 1;
                            q.push({nr, nc});
                        }
                    }
                // ����: �� �Ǵ� ���� ��
                } else if (cur == 6) {
                    if (i == 1 || i == 2) {
                        if (check(i, next)) {
                            visit[nr][nc] = visit[x][y] + 1;
                            q.push({nr, nc});
                        }
                    }
                // ����: �� �Ǵ� ���� ��
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
            // �־��� �ð� ���� �湮�Ͽ��� ��
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