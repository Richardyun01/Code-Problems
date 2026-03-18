from collections import deque

# 초기 입력
n, m = map(int, input().split())
grid = [list(map(int, input().split())) for _ in range(n)]

q = deque()
# 방문 여부 표시
vis = [[False] * m for _ in range(n)]

# 방향 설정
dr = [0, 0, 1, -1]
dc = [-1, 1, 0, 0]

pic, max_cnt = 0, 0
# 그리드 전체에 대해서
for i in range(n):
    for j in range(m):
        # 아직 방문하지 않은 1을 찾은 경우
        if grid[i][j] == 1 and not vis[i][j]:
            # 시작점 정의: 시작 좌표를 큐에 넣고 그림 넓이를 1로 초기화
            q.append((i, j))
            vis[i][j] = True
            cnt = 1
            # BFS: 현재 위치를 꺼내서 연결된 1을 탐색
            while len(q) != 0:
                r, c = q.popleft()
                # 각 방향의 좌표로 이동하여
                for k in range(4):
                    nr, nc = r + dr[k], c + dc[k]
                    # 도화지를 벗어나는 경우 무시
                    if nr < 0 or n <= nr or nc < 0 or m <= nc:
                        continue
                    # 인접한 좌표가 1이고 아직 방문하지 않으면 큐에 넣어 방문처리
                    if grid[nr][nc] == 1 and not vis[nr][nc]:
                        q.append((nr, nc))
                        vis[nr][nc] = True
                        cnt += 1
            max_cnt = max(max_cnt, cnt)
            pic += 1

print(pic)
print(max_cnt)