# 접근 방법 및 구현
# - BFS로 2차원 배열을 탐색하여 석유가 존재하는 좌표 검색
# - 석유가 존재하는 좌표에서 붙어 있는 좌표를 탐색
# - 현재 석유의 모든 y 좌표를 탐색해 현재 좌표에서 얻을 수 있는 석유의 크기를 증가
# - BFS 탐색 종료 시 석유가 존재하는 열 set을 따로 정의해 set를 순회하여 원래 oil 리스트에 인접 영역의 석유의 양인 cnt를 더함
# - 모든 좌표 탐색 후 석유의 정보가 저장된 oil 배열을 탐색

from collections import deque

def solution(land):
    answer = 0
    n, m = len(land), len(land[0])
    # 방문배열
    visited = [[False]*m for _ in range(n)]
    # 각 열의 기름의 총량을 저장
    oil = [0]*m
    dirs = [(0, 1), (1, 0), (-1, 0), (0, -1)]
    
    def bfs(row, col):
        queue = deque()
        queue.append([row, col])
        visited[row][col] = True
        cnt = 1
        # bfs 탐색 중 석유가 있는 열 중복을 방지하기 위한 set
        oil_covered = {col}
        while queue:
            pr, pc = queue.popleft()
            for dr, dc in dirs:
                nr, nc = pr+dr, pc+dc
                if 0 <= nr < n and 0 <= nc < m and land[nr][nc] == 1 and not visited[nr][nc]:
                    queue.append([nr, nc])
                    visited[nr][nc] = True
                    cnt += 1
                    # 현재 석유를 발견한 열 추가
                    oil_covered.add(nc)
            # print(f"cnt: {cnt}")
            # print(f"oil_covered: {oil_covered}")
        # 각 열을 돌면서 석유량 추가
        for c in oil_covered:
            oil[c] += cnt
    # bfs 탐색
    for i in range(n):
        for j in range(m):
            if land[i][j] == 1 and not visited[i][j]:
                bfs(i, j)
    answer = max(oil)
                
    return answer