/*
  �˰��� �з�: �׷��� �̷�, �׷��� Ž��, �ʺ� �켱 Ž��, ���� �켱 Ž��

  ���� ��� �� ����
  - ����-���� �׷����̹Ƿ� �迭 ��� ����
  - DFS: ���� �������� ������ �湮���� ���� �̿��� Ž���� �� ���
  - BFS: ���� ������ ť�� �ְ� �ϳ��� ������ �̿����� ť�� ����, �־��� �̿��� ť�� �湮 ǥ��
  - �ٸ� DFS/BFS ������ �޸� dx�� dy�� �غ��� �ʿ䰡 ����
*/

#include<iostream>
#include<queue>
#define endl '\n'
using namespace std;
int N, M, V;
int graph[1001][1001];
bool visited[1001];
queue<int> q;
void DFS(int v) {
    visited[v] = true;
    cout << v << ' ';
    for (int i = 1; i <= N; i++) {
        // ���� ������ ����ǰ� �湮���� �ʾ�����
        if (graph[v][i] == 1 && visited[i] == 0) {
// cout << "v: " << v << " i: " << i << endl;
            DFS(i);
        }
    }
}
void BFS(int v) {
    q.push(v);
    visited[v] = true;
    cout << v << ' ';
    while (!q.empty()) {
        v = q.front();
// cout << "v: " << v << endl;
        q.pop();
        for (int i = 1; i <= N; i++) {
            // ���� ������ ����ǰ� �湮���� �ʾ�����
            if (graph[v][i] == 1 && visited[i] == 0) {
// cout << "v: " << v << " i: " << i << endl;
                q.push(i);
                visited[i] = true;
                cout << i << ' ';
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M >> V;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }
    for (int i = 0; i <= N; i++) {
        visited[i] = 0;
    }
    DFS(V);
    cout << endl;
    for (int i = 0; i <= N; i++) {
        visited[i] = 0;
    }
    BFS(V);
    return 0;
}