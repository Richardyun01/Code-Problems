from collections import deque

n = int(input())
grid = [list(input().strip()) for _ in range(n)]
vis = [[False] * n for _ in range(n)]
dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]
ans1, ans2 = 0, 0

def BFS(a, b):
    q = deque()
    q.append((a, b))
    vis[a][b] = True
    while q:
        // 현재 좌표
        x, y = q.popleft()
        // 모든방향에 대해서
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            // 그리드 내에 존재하고 방문한 적 없고 인접한 좌표 알파벳이 같을 시
            if nx >= 0 and ny >= 0 and nx < n and ny < n:
                if vis[nx][ny] == False:
                    if grid[nx][ny] == grid[x][y]:
                        vis[nx][ny] = True
                        q.append((nx, ny))

// 일반인
for i in range(n):
    for j in range(n):
        if vis[i][j] == False:
            BFS(i, j)
            ans1 += 1
// 적록색맹
vis = [[False] * n for _ in range(n)]
for i in range(n):
    for j in range(n):
        if grid[i][j] == 'G':
            grid[i][j] = 'R'
for i in range(n):
    for j in range(n):
        if vis[i][j] == False:
            BFS(i, j)
            ans2 += 1
print(ans1)
print(ans2)