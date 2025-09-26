/*
  �˰��� �з�: �׷��� �̷�, �׷��� Ž��, �ʺ� �켱 Ž��, ���� �켱 Ž��, ���� �׷���, �÷��� ��
  
  ���� ��� �� ����
  - BFS�� ������ ���� Ž���ϴ� ����
  - �湮���� ���� ���� �߰��� ������ BFS�� ����� ĭ�� ���� �湮 ǥ���ϰ� Ƚ�� ����
  - �� �׽�Ʈ ���̽����� �迭�� �ʱ�ȭ �ʿ�
*/

#include<iostream>
#include<vector>
#include<queue>
#define endl '\n'
using namespace std;
int T, M, N, K;
int plant[51][51];
bool visited[51][51];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void bfs(int sy, int sx) {
    queue<pair<int, int>> q;
    visited[sy][sx] = true;
    q.push({sy, sx});
    while (!q.empty()) {
        auto [y, x] = q.front(); q.pop();
        for (int dir = 0; dir < 4; ++dir) {
            int ny = y + dy[dir];
            int nx = x + dx[dir];
            // ä�ҹ� ����
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
            // ���߰� �ְ� ���� �湮���� ������ ť�� �߰�
            if (plant[ny][nx] == 1 && !visited[ny][nx]) {
// cout << "ny: " << ny << " nx: " << nx << endl;
                visited[ny][nx] = true;
                q.push({ny, nx});
            }
        }
    }
// cout << "ended" << endl;
}
int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        int res = 0;
        cin >> M >> N >> K;
        // tc���� �ʱ�ȭ
        for (int i = 0; i < N; i++) {
            fill(plant[i], plant[i]+M, 0);
            fill(visited[i], visited[i]+M, false);
        }
        for (int j = 0; j < K; j++) {
            int x, y;
            cin >> x >> y;
            plant[y][x] = 1;
        }
        // ���ο� ������ �߰� �� BFS ����
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (plant[i][j] == 1 && !visited[i][j]) {
                    bfs(i, j);
                    res++;
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}