/*
  �˰��� �з�: �׷��� �̷�, �׷��� Ž��, �ʺ� �켱 Ž��, ���� �׷���

  ���� ��� �� ����
  - ��ǥ ������ pair�� ����� ��ġ�� ����
  - �湮 ó���� ���ؼ� ��ǥ�� �Ÿ��� �����ϴ� �迭�� -1�� �ʱ�ȭ -> ���� �Ұ��� ��ġ�� �ǹ�
  - �ð����⵵�� ���̱� ���� ��ǥ �������� ��� ��ǥ�� �湮: �������� �����ϸ� n^2�� n^2�� �ؾ��ϱ� ����
  - ��ǥ ����=���� ��ġ: 0���� ǥ��
*/

#include<iostream>
#include<queue>
#define endl '\n'
using namespace std;
int N, M;
int map[1002][1002];
int dist[1002][1002];
pair<int, int> goal;
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, -1, 0, 1};
void bfs() {
    // ������: ��ǥ ����
    queue<pair<int, int>> q;
    q.push(goal);
    // ��ǥ ������ �� 0
    dist[goal.first][goal.second] = 0;
    while (!q.empty()) {
        // ���� ��ġ
        pair<int, int> cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            // �̵��� ��ġ
            pair<int, int> next = {
                cur.first+dy[i], cur.second+dx[i]
            };
// cout << cur.first+dy[i] << ' ' << cur.second+dx[i] << endl;
            // ���� ���� ��� ��ŵ
            if (next.first < 0 || next.first >= N || next.second < 0 || next.second >= M) {
// cout << "out" << endl;
                continue;
            }
            // �̹� �������ų� ���̸� ��ŵ
            if (dist[next.first][next.second] != -1) {
// cout << "passed/wall" << endl;
                continue;
            }
            // ���� ��ġ/��ǥ �������� �Ÿ� ����
            q.push(next);
            dist[next.first][next.second] = dist[cur.first][cur.second] + 1;
// cout << dist[cur.first][cur.second] << ' ' << dist[next.first][next.second] << endl;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    fill(&dist[0][0], &dist[1001][1001], -1);
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
            if (map[i][j] == 2) {
                goal.first = i;
                goal.second = j;
            }
            // ���� �� 
            if (map[i][j] == 0) {
                dist[i][j] = 0;
            }
        }
    }
    bfs();
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}