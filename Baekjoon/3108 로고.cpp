/*
  알고리즘 분류: 자료 구조, 기하학, 분리 집합

  접근 방법
  - 두 그림이 서로 연결되어 있으면 한 번의 연속 스트로크로 그릴 수 있음
  - 두 그림이 서로 연결되어 있지 않으면 한 번의 연속 스트로크로 그릴 수 없음
    - 하나의 스트로크를 완료한 후 다른 스트로크를 그리기 위해서는 PU로 선을 그리지 않고 위치를 옮겨야 함
  - 초기 상태: (0, 0), 연필 내려짐
    - (0, 0)이 그림에 포함된다면 처음부터 그 스트로크를 그릴 수 있음
    - (0, 0)이 그림에 포함되지 않는다면 그림 외의 경로가 그려지는 것을 막기 위해 출발 전 PU로 그림의 한 점으로 이동해야 함
  - 필요한 PU 명령의 최소 횟수: 스트로크 개수 = k일 때
    - (0, 0)이 어느 한 그림에 포함되면 바로 시작 가능하므로 추가 PU는 k-1
    - (0, 0)이 그림에 포함되지 않으면 PU는 k
  - PD는 별도 카운트가 아니므로 셀 필요 없음
  - 연결성 결정 방법
    - 수평-수평: 두 선분이 같은 y좌표에 있고 x구간이 겹치거나 맞닿을 때
    - 수직-수직: 두 선분이 같은 x좌표에 있고 y구간이 겹치거나 맞닿을 때
    - 수평-수직: 수평 선분의 x구간 내에 수직 선분의 x좌표가 있고 수직 선분의 y구간 내에 수평 선분의 y좌표가 있을 때
  - 모든 선분을 정점-간선 그래프로 보고 교집합이 있는지 검사해야 함

  구현
  - Edge 구조체: 각 선분을 수평/수직 여부, 상수 좌표, 구간으로 표현
  - Union-Find: 전체 4N 선분에 대해 두 선분이 조건에 맞개 교차/접촉하면 두 선분을 같은 집합으로 합침
  - 교차 검사
    - 수평-수평: 같은 y좌표이고 x구간이 겹치면 true
    - 수직-수직: 같은 x좌표이고 y구간이 겹치면 true
    - 수평-수직: 수직 선분의 x가 수평 선분의 x구간 내에 있고 수평 성분의 y가 수직 선분의 y구간 내에 있으면 true
  - 각 선분이 (0, 0)을 포함하는지 검사하여 union-find root별로 기록
*/

#include <bits/stdc++.h>
using namespace std;
struct Edge {
    bool vertical;
    int c;
    int l, r;
};
struct UnionFind {
    vector<int> parent;
    UnionFind(int n) : parent(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    int find(int a) {
        if (parent[a] == a) return a;
        return parent[a] = find(parent[a]);
    }
    void uni(int a, int b) {
        a = find(a);
        b = find(b);
        if (a != b) parent[b] = a;
    }
};
bool interval_overlap(int a, int b, int c, int d) {
    return max(a, c) <= min(b, d);
}
bool intersect(const Edge &e1, const Edge &e2) {
    if (!e1.vertical && !e2.vertical) {
        if (e1.c == e2.c && interval_overlap(e1.l, e1.r, e2.l, e2.r)) return true;
        return false;
    }
    if (e1.vertical && e2.vertical) {
        if (e1.c == e2.c && interval_overlap(e1.l, e1.r, e2.l, e2.r)) return true;
        return false;
    }
    const Edge &h = (!e1.vertical) ? e1 : e2;
    const Edge &v = (e1.vertical) ? e1 : e2;
    if (v.c >= h.l && v.c <= h.r && h.c >= v.l && h.c <= v.r) return true;
    return false;
}
int main() {
    int N;
    cin >> N;
    vector<Edge> edges;
    edges.reserve(N*4);
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        {
            Edge e;
            e.vertical = false;
            e.c = y1;
            e.l = x1;
            e.r = x2;
            edges.push_back(e);
        }
        {
            Edge e;
            e.vertical = false;
            e.c = y2;
            e.l = x1;
            e.r = x2;
            edges.push_back(e);
        }
        {
            Edge e;
            e.vertical = true;
            e.c = x1;
            e.l = y1;
            e.r = y2;
            edges.push_back(e);
        }
        {
            Edge e;
            e.vertical = true;
            e.c = x2;
            e.l = y1;
            e.r = y2;
            edges.push_back(e);
        }
    }
    int M = edges.size();
    UnionFind uf(M);
    for (int i = 0; i < M; i++) {
        for (int j = i+1; j < M; j++) {
            if (intersect(edges[i], edges[j])) {
                uf.uni(i, j);
            }
        }
    }
    unordered_map<int, bool> comp_has_origin;
    for (int i = 0; i < M; i++) {
        int root = uf.find(i);
        bool contains_origin = false;
        if (!edges[i].vertical) {
            if (edges[i].c == 0 && (0 >= edges[i].l && 0 <= edges[i].r)) contains_origin = true;
        } else {
            if (edges[i].c == 0 && (0 >= edges[i].l && 0 <= edges[i].r)) contains_origin = true;
        }
        if (comp_has_origin.find(root) == comp_has_origin.end()) {
            comp_has_origin[root] = contains_origin;
        } else {
            comp_has_origin[root] = comp_has_origin[root] || contains_origin;
        }
    }
    int comp_cnt = comp_has_origin.size();
    bool origin_found = false;
    for (auto &p : comp_has_origin) {
        if (p.second) {
            origin_found = true;
            break;
        }
    }
    int res = origin_found ? comp_cnt - 1 : comp_cnt;
    cout << res;
    return 0;
}
