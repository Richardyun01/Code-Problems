/*
  ���� ��� �� ����
  - �밢������ ��ǥ�� �̵��ϵ��� DFS�� ����
  - ��忡�� ���Ǿ��� ���ڸ� ������� �����鼭 ��� �������� �ǵ��ư��µ� �ʿ��� �̵� Ƚ���� ���
  - �������� ���: �̹� ����� ���ڿ��� �� ������ ���� �����̸� �Լ� ������ ����ؾ� ��(���� ������ �湮 ó�� X)
  - ���������� �ٷ� ���ƿ��� �ʵ��� ����
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
    // ���������� ���ƿ��� �� �ִ밪 ����/�ٷ� ���ƿ��� ��� ����
    if (cur.first == src.first && cur.second == src.second && cnt > 1) {
        if (max_val < cnt) max_val = cnt;
        return;
    }
    // �����ϰų� ����
    for (int i = 0; i < 2; i++) {
        // �簢���� 4�������� ȸ�� ����
        if (dir+i >= 4) break;
        int nr = cur.first + dr[dir+i];
        int nc = cur.second + dc[dir+i];
        if (nr < 0 || nc < 0 || nr >= n || nc >= n) continue;
        // ���� �湮���� �ʾҰ� ���� ����Ʈ�� ���� �ʾ��� ���
        if (!vis[nr][nc] && !used[map[nr][nc]]) {
            // �ش� ����Ʈ ����
            used[map[nr][nc]] = true;
// cout << "dfs map[" << nr << "][" << nc << "]: " << map[nr][nc] << endl;
            dfs({nr, nc}, dir+i, cnt+1);
            // �湮 ����, ��� ����
            vis[nr][nc] = false;
            used[map[nr][nc]] = false;
        // ���� �������� ���ƿ� �� �ִ� ���
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