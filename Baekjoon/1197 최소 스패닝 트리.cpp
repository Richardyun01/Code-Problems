/*
  �˰��� �з�: �׷��� �̷�, �ּ� ���д� Ʈ��

  ���� ��� �� ����
  - ����ü: �� ������ ����ġ�� ������ ����
  - ������ ����ġ ������������ �����ϱ� ���� �Լ�
  - ��� ������ �̿��� Union-Find ����
  - Union by rank ������� �� ������ ���� �������� ��ħ
  - ������ ����ġ ������������ ���� �� �� ������ Ȯ���ϸ� ����Ŭ�� �������� ������ MST�� �߰�
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