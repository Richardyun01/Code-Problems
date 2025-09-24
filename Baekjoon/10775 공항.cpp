/*
  �˰��� �з�: �ڷ� ����, �׸��� �˰���, �и� ����

  ���� ��� �� ����
  - ��� �������� ��Ʈ ��� �˻�
  - a�� b�� �θ�� �����Ͽ� �� ���� ������ ����
  - ��ŷ ������ ����Ʈ �߰� �� �׺��� �ϳ� ���� ��ȣ�� ����Ʈ�� ����
  - find(gi) == 0�� �� �� ��ŷ�� �� �����Ƿ� ����
*/

#include <bits/stdc++.h>
using namespace std;
vector<int> parent;
int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
void merge(int a, int b) {
    a = find(a);
    b = find(b);
    parent[a] = b;
}
int main() {
    int G, P;
    cin >> G >> P;
    parent.resize(G+1);
    for (int i = 0; i <= G; i++) {
        parent[i] = i;
    }
    int ans = 0;
    for (int i = 0; i < P; i++) {
        int gi;
        cin >> gi;
        int gate = find(gi);
        if (gate == 0) break;
        merge(gate, gate-1);
        ans++;
    }
    cout << ans;
    return 0;
}
