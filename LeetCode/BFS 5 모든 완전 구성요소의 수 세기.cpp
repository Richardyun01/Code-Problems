class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // 양방향 연결 그래프 구성
        vector<vector<int>> adj(n+1);
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // 노드의 방문 여부
        vector<bool> vis(n+1, false);
        int ans = 0;

        // 모든 노드에 대해서
        for (int i = 0; i < n; i++) {
            // 현재 노드가 방문되었다면 패스
            if (vis[i] == true) {
                continue;
            }
            // 현재 노드와 연결된 노드들을 담는 리스트
            vector<int> bfs;
            bfs.push_back(i);
            // 현재 노드를 방문한 것으로 처리
            vis[i] = true;
            // bfs 리스트에 대해서
            for (int idx = 0; idx < bfs.size(); idx++) {
                // 현재 노드와 연결된 모든 이웃에 대해
                int j = bfs[idx];
                // 아직 방문하지 않은 노드면 연결 리스트에 포함시키고 방문 처리
                for (auto k : adj[j]) {
                    if (vis[k] == false) {
                        vis[k] = true;
                        bfs.push_back(k);
                    }
                }
            }
            // 연결 요소의 노드 수가 bfs의 크기일 때 각 노드가 나머지 모든 노드와 연결되어 있으면 완전 그래프
            bool check = true;
            for (auto j : bfs) {
                if (adj[j].size() != bfs.size()-1) {
                    check = false;
                }
            }
            if (check == true) {
                ans++;
                // cout << "ans: " << ans << endl;
            }
        }
        return ans;
    }
};