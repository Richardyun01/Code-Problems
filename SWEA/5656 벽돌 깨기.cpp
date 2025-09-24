/*
  ���� ��� �� ����
  - ������ ��� ��� ��츦 Ž���ؾ� �ϹǷ� ���Ʈ ���� ����� �̿�
  - ������ ��ġ�� ���� ������ ������ ����Ʈ��
  - 4������ ������ ���� ������ŭ Ž���ϸ鼭 ���� ����
  - �Ʒ������� ������ �͸� ť�� ���ʷ� ���� �� �ٽ� ������ ����
  - ���� ����Ʈ���� -> ���� -> ���� -> ���Ž��
  - ���� ������ �ּ� = ���� ���� ���� - ��Ʈ�� ���� ������ �ִ�
*/

#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#define endl '\n'
using namespace std;
int N, W, H, res;
int total_bricks;
int map[15][12];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
// ��ǥ�� �� ���ο� �ִ��� Ȯ��
bool is_inner(int x, int y) {
    if (x < 0 || x >= H || y < 0 || y >= W) return false;
    return true;
}
// ���� ����/���� ����
int remove_brick(int x, int y) {
    // ���� ����
    int power = map[x][y];
    map[x][y] = 0;
    // ���ŵ� ���� ��
    int ret = 1;
// cout << "remove_brick (" << x << "," << y << ") power " << power << endl;
    // �����¿� �������� ����
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < power; j++) {
            int nx = x + (dx[i]*j);
            int ny = y + (dy[i]*j);
            if (!is_inner(nx, ny)) break;
            if (map[nx][ny] > 0) {
                // �ֺ� ���� ����
                ret += remove_brick(nx, ny);
            }
        }
    }
    return ret;
}
// ���� ���� �� �Ʒ��� ����Ʈ��
void fall_brick() {
    for (int j = 0; j < W; j++) {
        queue<int> q;
        for (int i = H-1; i >= 0; i--) {
            // ���� ���� �� ť�� ����
            if (map[i][j] > 0) q.push(map[i][j]);
            map[i][j] = 0;
        }
        int col = H - 1;
        // ť�� �ִ� ������ �Ʒ����� ä��
        while (!q.empty()) {
            map[col][j] = q.front();
            q.pop();
            col--;
        }
    }
}
// ���� ����Ʈ�� ���� ����
int simulation(int col) {
    int removed = 0;
    for (int i = 0; i < H; i++) {
        // �� �� ���� ����-����
        if (map[i][col] > 0) {
// cout << "start col " << col << " row " << i << endl;
            removed = remove_brick(i, col);
            fall_brick();
            break;
        }
    }
    return removed;
}
// ���� ����Ʈ�� �� ����
int select_pos(int cnt) {
    // ��� ���� ��� ��
    if (cnt == N) return 0;
    int ret = 0;
    // ���� �� ����
    int tmp[15][12];
    memcpy(tmp, map, sizeof(tmp));
    for (int i = 0; i < W; i++) {
        // �ش� ���� ����
        int removed = simulation(i);
// cout << "cnt " << cnt << " col " << i << " removed " << removed << endl;
        // ���� ���� ���Ϸ� �ִ� ���� �� ���
        ret = max(ret, select_pos(cnt+1)+removed);
        memcpy(map, tmp, sizeof(map));
    }
    return ret;
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
		cin >> N >> W >> H;
		total_bricks = 0;
		res = 0;
		for (int i = 0; i < H; i++) {
		    for (int j = 0; j < W; j++) {
		        cin >> map[i][j];
		        if (map[i][j] != 0) total_bricks++;
		    }
		}
		res = total_bricks - select_pos(0);
		cout << '#' << tc << ' ' << res << endl;
	}
	return 0;
}
?