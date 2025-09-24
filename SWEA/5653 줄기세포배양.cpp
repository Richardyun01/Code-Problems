/*
  접근 방법 및 구현
  - 배양 용기 크기: 초기 50 + 배양 시간 300 = 최대 350
  - 상하좌우로 300/2=150만큼 번식하므로 (150, 150)에서 초기 배양 용기 저장 설정
  - 입력받은 값 != 0: 줄기세포이므로 우선순위 큐에 저장
  - 생명력이 높은 순서대로 세포 꺼내서 4방향으로 세포 없을 시 번식, 번식할 때마다 세포 수 증가
  - 비활성화 시간: t = 0, 번식 시간: 1초 후인 t = -1
  - 활성화된 세포가 죽는 시간: -(생명력 수치) 시간 -> dead 증가
  - K 시간 이후 살아있는 세포의 수: len - dead
*/

#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#define endl '\n'
using namespace std;
struct Cell {
    int x;
    int y;
    int X;
    int t;  // 현재 남은 생명력
};
struct cmp {
    bool operator()(Cell a, Cell b) {
        return a.X < b.X;
    }
};
int N, M, K;
int tmp, len, dead, x, y, nx, ny, X;
// 초기 배양 용기
int map[350][350];
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};
vector<Cell> cells;
priority_queue<Cell, vector<Cell>, cmp> activation;
// 확산: 세포 배양
void bfs() {
    while (!activation.empty()) {
        // 생명력이 큰 순서대로 세포 꺼내기
        x = activation.top().x;
        y = activation.top().y;
        X = activation.top().X;
// cout << "x, y, X: " << x << ' ' << y << ' ' <<  X << endl;
        activation.pop();
        // 4방향으로 번식
        for (int i = 0; i < 4; i++) {
            nx = x+dr[i];
            ny = y+dc[i];
            // 세포가 없을 시 세포 배양
            if (map[nx][ny] == 0) {
                map[nx][ny] = X;
                cells.push_back({nx, ny, X, X});
                len++;
            }
        }
// cout << "len: " << len << endl;
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
	    memset(map, 0, sizeof(map));
	    cells.clear();
	    dead = 0;
		cin >> N >> M >> K;
	    for (int i = 0; i < N; i++) {
	        for (int j = 0; j < M; j++) {
	            cin >> tmp;
	            map[150+i][150+j] = tmp;
	            if (tmp != 0) {
	                cells.push_back({150+i, 150+j, tmp, tmp});
	            }
	        }
	    }
	    len = cells.size();
	    while (K > 0) {
	        K--;
	        for (int i = 0; i < len; i++) {
	            cells[i].t--;
	            // 비활성화 상태:활성화
	            if (cells[i].t == -1) activation.push(cells[i]);
	            // 활성화 상태: 죽음
	            if (cells[i].t == -cells[i].X) dead++;
// cout << cells[i].t << " dead: " << i+1 << ": " << dead << endl;
	        }
	        bfs();
	    }
	    cout << '#' << tc << ' ' << len-dead << endl;
	}
	return 0;
}
?