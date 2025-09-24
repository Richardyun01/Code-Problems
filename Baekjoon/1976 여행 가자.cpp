/*
  �˰��� �з�: �ڷᱸ��, �׷��� �̷�, �׷��� Ž��, �и� ����

  ���� ��� �� ����
  - Union-Find �˰���
    - ��� �������� ����ȭ
    - �� ���ø� ���� �������� ��ħ
  - ���� ���� ���� ó��: ���� ����� �Է� �޾� ����� ���õ��� ���� �������� ��ħ
  - ���� ��� Ȯ��
    - ���� ��ȹ�� ���� ��� ���ð� ���� ���տ� �ִ��� �˻�
    - �ϳ��� �ٸ� �����̶�� ������ �Ұ���
*/

#include <bits/stdc++.h>
using namespace std;
int find(vector<int>& parent, int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent, parent[x]);
}
void unite(vector<int>& parent, int a, int b) {
    a = find(parent, a);
    b = find(parent, b);
    if (a != b) parent[b] = a;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> parent(n+1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int con;
            cin >> con;
            if (con == 1) unite(parent, i, j);
        }
    }
    vector<int> travel(m);
    for (int i = 0; i < m; i++) {
        cin >> travel[i];
    }
    bool possible = true;
    for (int i = 1; i < m; i++) {
        if (find(parent, travel[i-1]) != find(parent, travel[i])) {
            possible = false;
            break;
        }
    }
    cout << (possible ? "YES" : "NO") << endl;
    return 0;
}