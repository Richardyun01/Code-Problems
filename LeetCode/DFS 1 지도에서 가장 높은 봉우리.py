# BFS
class Solution:
    def highestPeak(self, isWater: List[List[int]]) -> List[List[int]]:
        m, n = len(isWater), len(isWater[0])
        # 전체 지도 높이 초기화
        height = [[-1] * n for _ in range(m)]
        bfs = deque([])
        # 특정 칸에 물이 존재할 시 BFS 대상으로 지정, 높이를 0으로 설정
        for r in range(m):
            for c in range(n):
                if isWater[r][c] == 1:
                    bfs.append((r, c))
                    height[r][c] = 0

        # 방향(상하좌우, 중앙)
        dirc = [0, 1, 0, -1, 0]
        while bfs:
            # 현재 물이 존재하는 좌표에 대해서
            r, c = bfs.popleft()
            for i in range(4):
                # 자기 자신을 포함한 전 방향으로 이동
                nr, nc = r + dirc[i], c + dirc[i+1]
                # 이동한 위치가 맵을 벗어나거나 높이가 결정되지 않았다면 패스
                if nr < 0 or nr == m or nc < 0 or nc == n or height[nr][nc] != -1:
                    continue
                # 이동한 위치의 높이를 원래 위치보다 1 높임
                height[nr][nc] = height[r][c] + 1
                # 제대로 된 값을 얻었으므로 bfs에서 사용하도록 처리
                bfs.append((nr, nc))
        return height