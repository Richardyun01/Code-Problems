#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int f, s, g, u, d;
// 방문 여부 및 버튼 클릭 횟수 배열
vector<int> b;
queue<int> q;
int main() {
    cin >> f >> s >> g >> u >> d;
    for (int i = 0; i <= f; i++) {
        b.push_back(0);
    }
    // bfs 큐 초기화
    q.push(s);
    // 시작 위치 방문 처리
    b[s] = 1;
    while (!q.empty()) {
        // 현재 층
        int cur = q.front();
        // 현재 층 버튼 클릭 횟수
        int depth = b[cur];
        q.pop();
        // 위/아래로 이동했을 때 도착할 층
        int up = cur + u;
        int down = cur - d;
        // 다음 이동할 곳이 목적지인 경우 종료
        if (up == g || down == g) {
            b[g] = depth + 1;
            break;
        }
        // 최고 층을 넘지 않고 아직 방문하지 않았다면 위로 이동
        if (up <= f && b[up] == 0) {
            q.push(up);
            b[up] = depth + 1;
        }
        // 1층 이하가 아니고 아직 방문하지 않았다면 아래로 이동
        if (down > 0 && b[down] == 0) {
            q.push(down);
            b[down] = depth + 1;
        }
    }
    // 목적지 배열에 값이 있을 시 도달
    if (b[g]) {
        cout << b[g] - 1;
    } else {
        cout << "use the stairs";
    }
    return 0;
}