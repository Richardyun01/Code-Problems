/*
  �˰��� �з�: �׷��� �̷�, �׷��� Ž��, �ʺ� �켱 Ž��

  ���� ��� �� ����
  - �� ��쿡 ���ؼ� Ž���� �ؾ� �ϹǷ� BFS�� �̿��ؾ� ��
  - ������ ã�� ������ �� x+1, x-1, x*2�� ���� visit�� �־� �湮�ߴ��� �˻�
  - �湮���� �ʾҴٸ� ������ ť�� ������ ��
  - ���� ť�� first�� ������ ��ġ�� ������ �� ����
*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int N, K;
bool visit[100001];
// ��� ������
int parent[100001];
// ���� ��ġ, �ɸ� �ð�: ����ġ�� ��� 1�� �� �ִ� �Ÿ� ����
queue<pair<int, int>> q;

void bfs(int n) {
    visit[n] = true;
    // ������
    parent[n] = -1;
    q.push({n, 0});
    while (!q.empty()) {
        int x   = q.front().first;
        int cnt = q.front().second;
        q.pop();
        // ��ǥ ������ �����ϸ� �� �̻� Ž���� �ʿ� ����
        if (x == K) {
            cout << cnt << '\n';
// // ��� ����
// vector<int> path;
// for (int v = K; v != -1; v = parent[v]) {
//     path.push_back(v);
// }
// reverse(path.begin(), path.end());
// for (size_t i = 0; i < path.size(); ++i) {
//     cout << path[i] << (i + 1 < path.size() ? ' ' : '\n');
// }
            return;
        }
        int next;
        // x+1
        next = x+1;
        if (0 <= next && next <= 100000 && !visit[next]) {
            visit[next] = true;
            parent[next] = x;
            q.push({next, cnt + 1});
// cout << "x+1: " << next << " " << cnt+1 << endl;
        }
        // x-1
        next = x-1;
        if (0 <= next && next <= 100000 && !visit[next]) {
            visit[next] = true;
            parent[next] = x;
            q.push({next, cnt+1});
// cout << "x-1: " << next << " " << cnt+1 << endl;
        }
        // x*2
        next = x*2;
        if (0 <= next && next <= 100000 && !visit[next]) {
            visit[next] = true;
            parent[next] = x;
            q.push({next, cnt+1});
// cout << "x*2: " << next << " " << cnt+1 << endl;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> K;
    fill(visit, visit+100001, false);
    fill(parent, parent+100001, -1);
    bfs(N);
    return 0;
}