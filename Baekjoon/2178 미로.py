from collections import deque

n, m = map(int, input().split())
grid = [input().strip() for _ in range(n)]
# 시작점으로부터의 거리
check = [[0] * m for _ in range(n)]
# 방문 여부
vis = [[False] * m for _ in range(n)]
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
def bfs(a, b):
    # 해당 지점에서 시작
    vis[a][b] = True
    q = deque([(a, b)])
    while q:
        # 큐 맨 앞의 위치에 대해
        x, y = q.popleft()
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            # 이동한 위치가 맵 내고 조건 만족 시
            if 0 <= nx < n and 0 <= ny < m:
                if grid[nx][ny] == '1' and vis[nx][ny] == False:
                    # 해당 지점의 진행도를 1 올리고 방문 처리, 큐에 넣음
                    check[nx][ny] = check[x][y] + 1
                    vis[nx][ny] = True
                    q.append([nx, ny])
bfs(0, 0)
print(check[n-1][m-1]+1)