/*
  알고리즘 분류: 그래프 이론, 최소 스패닝 트리

  접근 방법 및 구현
  - 구조체: 두 정점과 가중치를 변수로 가짐
  - 간선을 가중치 오름차순으로 정렬하기 위한 함수
  - 경로 압축을 이용한 Union-Find 연산
  - Union by rank 방법으로 두 정점을 같은 집합으로 합침
  - 간선을 가중치 오름차순으로 정렬 후 각 간선을 확인하며 사이클이 형성되지 않으면 MST에 추가
*/

#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u, v;
    int weight;
};
bool compare_edge(const Edge &a, const Edge &b) {
    return a.weight < b.weight;
}
int find(vector<int>& parent, int a) {
    if (parent[a] != a) parent[a] = find(parent, parent[a]);
    return parent[a];
}
void union_sets(vector<int>& parent, vector<int>& rank, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    if (a == b) return;
    if (rank[a] < rank[b]) swap(a, b);
    parent[b] = a;
    if (rank[a] == rank[b]) rank[a]++;
}
int main() {
    int V, E;
    cin >> V >> E;
    vector<Edge> edges;
    edges.reserve(E);
    for (int i = 0; i < E; i++) {
        Edge edge;
        cin >> edge.u >> edge.v >> edge.weight;
        edges.push_back(edge);
    }
    sort(edges.begin(), edges.end(), compare_edge);
    vector<int> parent(V+1);
    vector<int> rank(V+1, 0);
    for (int i = 1; i <= V; i++) {
        parent[i] = i;
    }
    long long mst_weight = 0;
    int edge_cnt = 0;
    for (const Edge &edge : edges) {
        if (find(parent, edge.u) != find(parent, edge.v)) {
            union_sets(parent, rank, edge.u, edge.v);
            mst_weight += edge.weight;
            edge_cnt++;
            if (edge_cnt == V-1) break;
        }
    }
    cout << mst_weight;
    return 0;
}