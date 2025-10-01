/*
  알고리즘 분류: 그래프 이론, 그래프 탐색, 너비 우선 탐색, 깊이 우선 탐색

  접근 방법 및 구현
  - DFS로 구현
  - 연결된 노드들을 연속해서 호출해 방문기록이 없는 연결된 노드가 없으면 종료
  - 인접 리스트 노드 중 방문기록이 없을 시 재실행
  - DFS가 실행되면 연결 노드 개수 증가
  - BFS로도 구현 가능
*/

#include<iostream>
#include<vector>
#define endl '\n'
using namespace std;
int N, M, res;
vector<vector<int>> graph;
vector<bool> check;
// 같은 연결요소의 모든 정점을 방문 처리
void DFS(int v) {
    // 이미 방문했을 시 종료
    if (check[v]) return;
    // 현재 정점 방문
    check[v] = true;
    for (int i : graph[v]) {
        // 아직 방문하지 않았을 시 계속 탐색
        if (check[i] == false) {
// cout << "check[" << i << "] == false" << endl;
            DFS(i);
        }
    }
}
int main() {
    ios::sync_with_stdio(NULL);
    cin.tie(false);
    cout.tie(false);
    cin >> N >> M;
    graph.resize(N+1);
    check = vector<bool>(N+1, false);
    for (int i = 0; i < M; i++) {
        int s, e;
        cin >> s >> e;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    for (int i = 1; i < N+1; i++) {
        // 탐색에 포함되지 않았을 시 카운트트
        if (!check[i]) {
// cout << "i: " << i << endl;
            res++;
            DFS(i);
        }
    }
    cout << res << endl;
    return 0;
}