# 접근 방법 및 구현
# - 지게차 요청은 한 번만 접근 가능한 것만 제거하므로 BFS를 이용해 연쇄 제거를 방지해야 함
# - 외부와 연결된 빈칸을 BFS로 표시
# - 동시에 제거해야 연쇄 제거가 일어나지 않음
# - 테두리에 있는 경우 바로 외부와 면이 닿으므로 제거 대상
# - 외부와 연결된 빈칸과 인접한 경우는 좌표를 통해 탐색
# - 크레인 요청은 전량 삭제이므로 단순 순회로 모두 제거

from collections import deque

def solution(storage, requests):
    n, m = len(storage), len(storage[0])
    grid = [list(row) for row in storage]
    dirs = [(-1,0),(1,0),(0,-1),(0,1)]
    
    def in_bounds(x, y):
        return 0 <= x < n and 0 <= y < m
    # 알파벳 전부 제거
    def remove_crane(ch):
        for i in range(n):
            for j in range(m):
                if grid[i][j] == ch:
                    grid[i][j] = '*'
    # 외부와 연결된 알파벳만 제거
    def remove_fork(ch):
        # 외부와 연결된 빈칸을 bfs로 표시
        vis = [[False]*m for _ in range(n)]
        q = deque()
        
        # 테두리의 빈칸을 시작점으로 추가
        for i in range(n):
            for j in (0, m-1):
                if grid[i][j] == '*' and not vis[i][j]:
                    vis[i][j] = True
                    q.append((i, j))
        for j in range(m):
            for i in (0, n-1):
                if grid[i][j] == '*' and not vis[i][j]:
                    vis[i][j] = True
                    q.append((i, j))
        # 빈칸만 퍼져나감
        while q:
            x, y = q.popleft()
            for dx, dy in dirs:
                nx, ny = x+dx, y+dy
                if in_bounds(nx, ny) and not vis[nx][ny] and grid[nx][ny] == '*':
                    vis[nx][ny] = True
                    q.append((nx, ny))
        # 제거 대상 수집
        to_remove = []
        for i in range(n):
            for j in range(m):
                if grid[i][j] != ch:
                    continue
                # 테두리에 있는 경우
                if i == 0 or i == n-1 or j == 0 or j == m-1:
                    to_remove.append((i, j))
                    continue
                # 외부와 연결된 빈칸과 인접한 경우
                for dx, dy in dirs:
                    ni, nj = i+dx, j+dy
                    if in_bounds(ni, nj) and grid[ni][nj] == '*' and vis[ni][nj]:
                        to_remove.append((i, j))
                        break
        for x, y in to_remove:
            grid[x][y] = '*'
    # 알파벳 수에 따라 작업
    for req in requests:
        ch = req[0]
        if len(req) == 2:
            remove_crane(ch)
        else:
            remove_fork(ch)
    answer = 0
    for i in range(n):
        for j in range(m):
            if grid[i][j] != '*':
                answer += 1
    return answer