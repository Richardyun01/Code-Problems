/*
  알고리즘 분류: 자료구조, 그래프 이론, 그래프 탐색, 분리 집합

  접근 방법 및 구현
  - Union-Find 알고리즘
    - 경로 압축으로 최적화
    - 두 도시를 같은 집합으로 합침
  - 도시 연결 정보 처리: 인접 행렬을 입력 받아 연결된 도시들을 같은 집합으로 합침
  - 여행 경로 확인
    - 여행 계획에 속한 모든 도시가 같은 집합에 있는지 검사
    - 하나라도 다른 집합이라면 여행이 불가능
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