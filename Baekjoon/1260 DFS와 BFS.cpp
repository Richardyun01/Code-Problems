/*
  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

  접근 방법 및 구현
  - 정점-간선 그래프이므로 배열 사용 가능
  - DFS: 시작 정점부터 시작해 방문하지 않은 이웃을 탐색할 시 재귀
  - BFS: 시작 정점을 큐에 넣고 하나씩 꺼내며 이웃들을 큐에 넣음, 넣어진 이웃은 큐에 방문 표시
  - 다른 DFS/BFS 문제와 달리 dx와 dy를 준비할 필요가 없음
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
        // 현재 정점과 연결되고 방문하지 않았으면
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
            // 현재 정점과 연결되고 방문하지 않았으면
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