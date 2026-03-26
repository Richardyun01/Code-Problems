#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        // 각 edge를 색에 따라서 구성
        vector<vector<vector<int>>> graph(2, vector<vector<int>>(n));
        for (const auto& edge : redEdges) {
            graph[0][edge[0]].push_back(edge[1]);
        }
        for (const auto& edge : blueEdges) {
            graph[1][edge[0]].push_back(edge[1]);
        }
        // 초기화: 모든 거리, 방문 여부., bfs 가능성(노드 0부터 시작)
        vector<int> min_dist(n, -1);
        vector<vector<bool>> vis(n, vector<bool>(2, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        q.push({0, 1});
        vis[0][0] = true;
        vis[0][1] = true;
        int dist = 0;

        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                // 현재 노드 가져오기
                pair<int, int> cur = q.front();
                q.pop();
                int cur_node = cur.first;
                int last_col = cur.second;
                // 현재 노드의 최소 거리가 정해지지 않았으면 현재 거리로 설정
                if (min_dist[cur_node] == -1) {
                    min_dist[cur_node] = dist;
                }
                // 색 반전
                int next_col = last_col ^ 1;
                // 그래프 내 인접한 edge에 대해서 방문하지 않았으면 탐색 대상에 추가
                for (int neigh : graph[next_col][cur_node]) {
                    if (!vis[neigh][next_col]) {
                        vis[neigh][next_col] = true;
                        q.push({neigh, next_col});
                    }
                }
            }
            // 다음 거리 레벨로 이동
            dist++;
        }
        return min_dist;
    }
};