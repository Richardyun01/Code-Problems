class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        // 전체 지도 높이 초기화
        vector<vector<int>> height(m, vector<int>(n, -1));
        deque<pair<int, int>> bfs;
        // 특정 칸에 물이 존재할 시 BFS 대상으로 지정, 높이를 0으로 설정
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (isWater[r][c] == 1) {
                    bfs.push_back({r, c});
                    height[r][c] = 0;
                }
            }
        }
        // 방향(상하좌우, 중앙)
        int dir[5] = {0, 1, 0, -1, 0};
        while (!bfs.empty()) {
            // 현재 물이 존재하는 좌표에 대해서
            pair<int, int> cur = bfs.front();
            bfs.pop_front();
            int r = cur.first;
            int c = cur.second;
            for (int i = 0; i < 4; i++) {
                // 자기 자신을 포함한 전 방향으로 이동
                int nr = r + dir[i];
                int nc = c + dir[i+1];
                // 이동한 위치가 맵을 벗어나거나 높이가 결정되지 않았다면 패스
                if (nr < 0 || nr == m || nc < 0 || nc == n || height[nr][nc] != -1) {
                    continue;
                }
                // 이동한 위치의 높이를 원래 위치보다 1 높임
                height[nr][nc] = height[r][c] + 1;
                // 제대로 된 값을 얻었으므로 bfs에서 사용하도록 처리
                bfs.push_back({nr, nc});
            }
        }
        return height;
    }
};