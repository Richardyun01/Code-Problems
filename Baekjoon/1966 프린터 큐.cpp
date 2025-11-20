/*
  알고리즘 분류: 구현, 자료 구조, 시뮬레이션, 큐

  접근 방법 및 구현
  - 인덱스와 중요도를 모두 저장하는 큐가 필요
  - 우선순위 큐에 중요도를 넣어 자동으로 정렬하게 함
  - 큐에서 하나씩 뽑아 현재 중요도와 우선순위 큐에 있는 중요도를 확인하여 인덱스가 일치할 때까지 반복
*/

#include<iostream>
#include<queue>
using namespace std;
int main() {
    int tc = 0;
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        int n, m;
        cin >> n >> m;
        int cnt = 0;
        queue<pair<int, int>> q;
        priority_queue<int> pq;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            q.push({i, x});
            pq.push(x);
        }
        while (!q.empty()) {
            int idx = q.front().first;
            int prior = q.front().second;
            q.pop();
            if (pq.top() == prior) {
                pq.pop();
                cnt++;
                if (idx == m) {
                    cout << cnt << endl;
                    break;
                }
            } else {
                q.push({idx, prior});
            }
        }
    }
    return 0;
}