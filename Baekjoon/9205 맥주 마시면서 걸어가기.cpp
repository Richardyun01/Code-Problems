#include<iostream>
#include<vector>
#include<cmath>
#include<cstring>
using namespace std;
int n;
int home_x, home_y;
int rock_x, rock_y;
bool vis[101];
bool dfs(vector<pair<int, int>> conv, int now_x, int now_y) {
    int conv_s = conv.size();
    // 현재 위치에서 목적지까지의 거리
    int f_dist = abs(now_x - rock_x) + abs(now_y - rock_y);
    // 만약 목적지까지의 거리가 1000 이하면 바로 도달 가능
    if (f_dist <= 1000) {
        return true;
    }
    // 갈 수 있는 경유지 탐색
    for (int i = 0; i < conv_s; i++) {
        // 이미 방문한 경유지 패스
        if (vis[i]) continue;
        // 현재 위치에서 i번째 경유지까지의 거리
        int conv_dist = abs(now_x - conv[i].first) + abs(now_y - conv[i].second);
        // 거리가 1000을 넘으면 한 번에 갈 수 없으므로 패스
        if (conv_dist > 1000) continue;
        // 방문했으므로 방문 처리
        vis[i] = true;
        // 해당 경유지로 이동한 상태에서 다시 갈 수 있는지 재귀 탐색
        if (dfs(conv, conv[i].first, conv[i].second)) {
            return true;
        }
    }
    return false;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<pair<int, int>> conv;
        cin >> n;
        cin >> home_x >> home_y;
        for (int j = 0; j < n; j++) {
            int tmp1, tmp2;
            cin >> tmp1 >> tmp2;
            conv.push_back({tmp1, tmp2});
        }
        cin >> rock_x >> rock_y;
        if (dfs(conv, home_x, home_y)) {
            cout << "happy" << endl;
        } else {
            cout << "sad" << endl;
        }
        memset(vis, 0, sizeof(vis));
    }
    return 0;
}