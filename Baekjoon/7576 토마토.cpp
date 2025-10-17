/*
  �˰��� �з�: �׷��� �̷�, �׷��� Ž��, �ʺ� �켱 Ž��, �ִ� ���, ���� �׷���

  ���� ��� �� ����
  - BFS�� �����ؾ� �ϹǷ� �丶���, �湮 ����, xy ����, �ӽ� ť�� ����
  - �켱 �湮 ���� �迭�� -1�� �ʱ�ȭ�� ���� ���� �κи� 0���� ����, BFS���� �湮 ������ ���̸� +1
  - BFS ó�� �� �湮 ���ο� ���� �ϼ� ����, �湮���� ���� ��� = �湮 �Ұ� ��Ұ� �ִٸ� -1�� ���
*/

#include<iostream>
#include<queue>
#define endl '\n';
using namespace std;
int M, N, res = -1;
int tomato[1001][1001];
// �湮 ����
int visited[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pair<int, int>> q;
void bfs() {
    while (!q.empty()) {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            // �� �̵�
            int na = a + dx[i];
            int nb = b + dy[i];
            // �ش� ���� �湮���� ���� �̵� ������ ���� ��: ť�� push�ϰ� �湮 ó��
            if (na >= 0 && nb >= 0 && N > na && M > nb && visited[na][nb] == -1 && tomato[na][nb] == 0) {
// cout << "na: " << na << " nb: " << nb << endl;
                q.push(make_pair(na, nb));
                visited[na][nb] = visited[a][b] + 1;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> M >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> tomato[i][j];
// cout << tomato[i][j] << ' ';
            // ���� �湮 ����
            visited[i][j] = -1;
            // ������
            if (tomato[i][j] == 1) {
                q.push(make_pair(i, j));
                visited[i][j]++;
            }
// cout << visited[i][j] << ' ';
        }
// cout << endl;
    }
    bfs();
    bool check = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
// cout << visited[i][j] << ' ';
            // ������ ������ res �� ����
            if (res <= visited[i][j]) {
                res = visited[i][j];
            }
            // �丶�䰡 ���µ� �湮 ������ ��� = ���� �Ұ����� ���
            if (tomato[i][j] == 0 && visited[i][j] == -1) {
                res = -1;
                check = true;
                break;
            }
        }
// cout << endl;
        if (check) {
            break;
        }
    }
    cout << res << endl;
    return 0;
}