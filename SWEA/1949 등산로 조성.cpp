/*
  ���� ��� �� ����
  - �������� ���� ���� ���̸� ����
  - �ش� ������ ���� ���� ��� ���ǿ� ���� �̵�
  - DFS�� ���� ���� Ž��
  - ���� ��ġ���� ���� ������ �̵��� ������ �� �ִ밪 ����
  - �̵��� �Ұ��������� ���� ���縦 ���� �ʾҰ� ���� ��ġ���� ���� ���� �� �ִٸ� ���� �� �̵�
  - �ٸ� ��� Ž���� ���� ��Ʈ��ŷ ����(�湮 ����)
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
        // ���� �� �̹湮
        if (nx >= 0 && ny >= 0 && nx < n && ny < n && !check[ny][nx]) {
            // ���� ��ġ���� ���� �ڵ�� �̵� ��
            if (map[ny][nx] < height) {
                cnt = max(cnt, dfs(ny, nx, map[ny][nx], digged));
            } else {
                // ���縦 ���� �ʾҰ� ���� ���� �� �ִ� ���
                if (!digged && map[ny][nx]-k < height) {
                    cnt = max(cnt, dfs(ny, nx, height-1, true));
// cout << "map[" << ny << "][" << nx << "]-" << k << " = " << map[ny][nx]-k << endl;
                }
            }
        }
    }
    // �湮 ����
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