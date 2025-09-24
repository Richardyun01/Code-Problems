/*
  알고리즘 분류: 자료 구조, 그리디 알고리즘, 분리 집합

  접근 방법 및 구현
  - 경로 압축으로 루트 노드 검색
  - a를 b의 부모로 설정하여 두 개의 집합을 병합
  - 도킹 가능한 게이트 발견 시 그보다 하나 작은 번호의 게이트와 병합
  - find(gi) == 0일 시 더 도킹할 수 없으므로 종료
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
