/*
  접근 방법 및 구현
  - 구슬을 쏘는 모든 경우를 탐색해야 하므로 브루트 포스 방법을 이용
  - 구슬의 위치를 정할 때마다 구슬을 떨어트림
  - 4방향을 벽돌의 폭발 범위만큼 탐색하면서 벽돌 제거
  - 아래서부터 벽돌인 것만 큐에 차례로 담은 후 다시 벽돌을 쌓음
  - 구슬 떨어트리기 -> 폭발 -> 낙하 -> 재귀탐색
  - 벽돌 개수의 최소 = 최초 벽돌 개수 - 깨트린 벽돌 개수의 최대
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
// 좌표가 맵 내부에 있는지 확인
bool is_inner(int x, int y) {
    if (x < 0 || x >= H || y < 0 || y >= W) return false;
    return true;
}
// 벽돌 제거/연쇄 폭발
int remove_brick(int x, int y) {
    // 폭발 범위
    int power = map[x][y];
    map[x][y] = 0;
    // 제거된 벽돌 수
    int ret = 1;
// cout << "remove_brick (" << x << "," << y << ") power " << power << endl;
    // 상하좌우 방향으로 전파
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < power; j++) {
            int nx = x + (dx[i]*j);
            int ny = y + (dy[i]*j);
            if (!is_inner(nx, ny)) break;
            if (map[nx][ny] > 0) {
                // 주변 벽돌 제거
                ret += remove_brick(nx, ny);
            }
        }
    }
    return ret;
}
// 벽돌 제거 후 아래로 떨어트림
void fall_brick() {
    for (int j = 0; j < W; j++) {
        queue<int> q;
        for (int i = H-1; i >= 0; i--) {
            // 벽돌 존재 시 큐에 저장
            if (map[i][j] > 0) q.push(map[i][j]);
            map[i][j] = 0;
        }
        int col = H - 1;
        // 큐에 있던 벽돌을 아래부터 채움
        while (!q.empty()) {
            map[col][j] = q.front();
            q.pop();
            col--;
        }
    }
}
// 구슬 떨어트려 벽돌 제거
int simulation(int col) {
    int removed = 0;
    for (int i = 0; i < H; i++) {
        // 맨 위 벽돌 제거-낙하
        if (map[i][col] > 0) {
// cout << "start col " << col << " row " << i << endl;
            removed = remove_brick(i, col);
            fall_brick();
            break;
        }
    }
    return removed;
}
// 구슬 떨어트릴 열 선택
int select_pos(int cnt) {
    // 모든 구슬 사용 시
    if (cnt == N) return 0;
    int ret = 0;
    // 현재 맵 상태
    int tmp[15][12];
    memcpy(tmp, map, sizeof(tmp));
    for (int i = 0; i < W; i++) {
        // 해당 열에 구슬
        int removed = simulation(i);
// cout << "cnt " << cnt << " col " << i << " removed " << removed << endl;
        // 다음 구슬 투하로 최대 제거 수 계산
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