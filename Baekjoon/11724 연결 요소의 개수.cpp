/*
  �˰��� �з�: �׷��� �̷�, �׷��� Ž��, �ʺ� �켱 Ž��, ���� �켱 Ž��

  ���� ��� �� ����
  - DFS�� ����
  - ����� ������ �����ؼ� ȣ���� �湮����� ���� ����� ��尡 ������ ����
  - ���� ����Ʈ ��� �� �湮����� ���� �� �����
  - DFS�� ����Ǹ� ���� ��� ���� ����
  - BFS�ε� ���� ����
*/

#include<iostream>
#include<vector>
#define endl '\n'
using namespace std;
int N, M, res;
vector<vector<int>> graph;
vector<bool> check;
// ���� �������� ��� ������ �湮 ó��
void DFS(int v) {
    // �̹� �湮���� �� ����
    if (check[v]) return;
    // ���� ���� �湮
    check[v] = true;
    for (int i : graph[v]) {
        // ���� �湮���� �ʾ��� �� ��� Ž��
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
        // Ž���� ���Ե��� �ʾ��� �� ī��ƮƮ
        if (!check[i]) {
// cout << "i: " << i << endl;
            res++;
            DFS(i);
        }
    }
    cout << res << endl;
    return 0;
}