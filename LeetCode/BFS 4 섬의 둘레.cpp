// DFS
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        // 전체 그리드의 가로세로 범위
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        // 각 셀에 대해서
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 일단 현재 셀이 땅일 시 모든 범위를 더한다고 가정
                if (grid[i][j] == 1) {
                    ans += 4;
                    // 모든 인접 셀을 확인할 필요 없음: 우/하측만 체크하면 됨, 다른 방향은 이미 해당 공유 모서리를 확인하였으므로 다시 할 필요 없음
                    // 인접한 우측 셀이 땅일 시 현재 셀의 아래 모서리와 아래쪽 셀의 윗 모서리가 경계선이 아님
                    if (i < m-1 && grid[i+1][j] == 1) {
                        ans -= 2;
                    }
                    // 인접한 하단 셀이 땅일 시 동일하게 공유되는 모서리의 값을 뺌
                    if (j < n-1 && grid[i][j+1] == 1) {
                        ans -= 2;
                    }
                }
            }
        }
        return ans;
    }
};