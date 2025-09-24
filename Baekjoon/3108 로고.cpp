/*
  �˰��� �з�: �ڷ� ����, ������, �и� ����

  ���� ���
  - �� �׸��� ���� ����Ǿ� ������ �� ���� ���� ��Ʈ��ũ�� �׸� �� ����
  - �� �׸��� ���� ����Ǿ� ���� ������ �� ���� ���� ��Ʈ��ũ�� �׸� �� ����
    - �ϳ��� ��Ʈ��ũ�� �Ϸ��� �� �ٸ� ��Ʈ��ũ�� �׸��� ���ؼ��� PU�� ���� �׸��� �ʰ� ��ġ�� �Űܾ� ��
  - �ʱ� ����: (0, 0), ���� ������
    - (0, 0)�� �׸��� ���Եȴٸ� ó������ �� ��Ʈ��ũ�� �׸� �� ����
    - (0, 0)�� �׸��� ���Ե��� �ʴ´ٸ� �׸� ���� ��ΰ� �׷����� ���� ���� ���� ��� �� PU�� �׸��� �� ������ �̵��ؾ� ��
  - �ʿ��� PU ����� �ּ� Ƚ��: ��Ʈ��ũ ���� = k�� ��
    - (0, 0)�� ��� �� �׸��� ���ԵǸ� �ٷ� ���� �����ϹǷ� �߰� PU�� k-1
    - (0, 0)�� �׸��� ���Ե��� ������ PU�� k
  - PD�� ���� ī��Ʈ�� �ƴϹǷ� �� �ʿ� ����
  - ���Ἲ ���� ���
    - ����-����: �� ������ ���� y��ǥ�� �ְ� x������ ��ġ�ų� �´��� ��
    - ����-����: �� ������ ���� x��ǥ�� �ְ� y������ ��ġ�ų� �´��� ��
    - ����-����: ���� ������ x���� ���� ���� ������ x��ǥ�� �ְ� ���� ������ y���� ���� ���� ������ y��ǥ�� ���� ��
  - ��� ������ ����-���� �׷����� ���� �������� �ִ��� �˻��ؾ� ��

  ����
  - Edge ����ü: �� ������ ����/���� ����, ��� ��ǥ, �������� ǥ��
  - Union-Find: ��ü 4N ���п� ���� �� ������ ���ǿ� �°� ����/�����ϸ� �� ������ ���� �������� ��ħ
  - ���� �˻�
    - ����-����: ���� y��ǥ�̰� x������ ��ġ�� true
    - ����-����: ���� x��ǥ�̰� y������ ��ġ�� true
    - ����-����: ���� ������ x�� ���� ������ x���� ���� �ְ� ���� ������ y�� ���� ������ y���� ���� ������ true
  - �� ������ (0, 0)�� �����ϴ��� �˻��Ͽ� union-find root���� ���
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
