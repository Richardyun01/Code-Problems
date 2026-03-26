# 모든 입력을 공백 단위로 쪼개서 하나의 리스트로 모으기
# 필요한 데이터가 다 모일 때까지 계속 읽기
all_data = []
while True:
    try:
        line = input().split()
        # 엔터만 치면 다음 입력을 기다리기
        if not line:
            continue
        # m, n, k를 읽은 후 필요한 좌표 개수가 다 채워졌는지 확인
        all_data.extend(line)
        if len(all_data) >= 3:
            m, n, k = map(int, all_data[:3])
            if len(all_data) >= k * 4 + 3:
                break
    except EOFError:
        break
        
nums = list(map(int, all_data))
m, n, k = nums[0], nums[1], nums[2]
grid = [[0] * n for _ in range(m)]
dx = [0, 0, -1, 1]
dy = [1, -1, 0, 0]
# 각 영역의 넓이 정의
areas = []

idx = 3
# 색칠된 부분 방문 처리
for _ in range(k):
    x1, y1, x2, y2 = nums[idx], nums[idx+1], nums[idx+2], nums[idx+3]
    idx += 4
    for y in range(y1, y2):
        for x in range(x1, x2):
            grid[y][x] = 1
            
# 빈공간 발견 시 bfs 처리
for i in range(m):
    for j in range(n):
        if grid[i][j] == 0:
            # 시작 위치 방문 처리
            grid[i][j] = 1
            q = [(i, j)]
            q_idx = 0
            # 현재 영역의 넓이
            cnt = 1
            while q_idx < len(q):
                y, x = q[q_idx]
                q_idx += 1
                # 모든 방향에 대해서
                for d in range(4):
                    ny, nx = y + dy[d], x + dx[d]
                    # 격자 범위내에 있고 아직 방문하지 않았으면
                    if 0 <= ny < m and 0 <= nx < n:
                        if grid[ny][nx] == 0:
                            grid[ny][nx] = 1
                            q.append((ny, nx))
                            # 영역 넓이 +1
                            cnt += 1
            areas.append(cnt)

print(len(areas))
areas.sort()
print(*(areas))