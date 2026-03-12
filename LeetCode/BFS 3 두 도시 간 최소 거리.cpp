class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        // 인접한 이웃 노드와 거리 정보를 저장하는 쌍
        vector<vector<pair<int, int>>> adj(n+1);
        // 각 정보를 저장
        for (auto road : roads) {
            int src = road[0];
            int dst = road[1];
            int dist = road[2];
            adj[src].push_back({dst, dist});
            adj[dst].push_back({src, dist});
        }

        int ans = 1e9;
        // 방문했음을 저장하는 벡터
        vector<bool> visit(n+1, false);
        // 1에서 시작함을 의미하는 초기화
        deque<int> q = {1};
        // 1번 노드는 이미 방문함
        visit[1] = true;

        while(!q.empty()) {
            // 현재 노드에 대해서
            int node = q.front();
            q.pop_front();
            // 각 이웃과 거리에 대해서
            for (auto edge : adj[node]) {
                int neigh = edge.first;
                int dist = edge.second;
                // 최소값을 현재 최소값과 거리와 비교
                ans = min(ans, dist);
                // 이웃 노드를 방문하지 않았다면 방문한 것으로 처리
                if (visit[neigh] == false) {
                    visit[neigh] = true;
                    q.push_back(neigh);
                }
            }
        }

        return ans;
    }
};