from collections import deque

f, s, g, u, d = map(int, input().split())
# 방문 여부 및 버튼 클릭 횟수 배열
b = []
q = deque()
b = [0] * (f+1)
# bfs 큐 초기화
q.append(s)
# 시작 위치 방문 처리
b[s] = 1
while q:
    # 현재 층
    cur = q.popleft()
    # 현재 층 버튼 클릭 횟수
    depth = b[cur]
    # 위 아래로 이동했을 때 도착할 층
    up = cur + u
    down = cur - d
    # 다음 이동할 곳이 목적지인 경우 종료
    if up == g or down == g:
        b[g] = depth + 1
        break
    # 최고 층을 넘지 않고 아직 방문하지 않았다면 위로 이동
    if up <= f and b[up] == 0:
        q.append(up)
        b[up] = depth + 1
    # 1층 이하가 아니고 아직 방문하지 않았다면 아래로 이동
    if down > 0 and b[down] == 0:
        q.append(down)
        b[down] = depth + 1
# 목적지 배열에 값이 있을 시 도달
if b[g]:
    print(b[g]-1)
else:
    print("use the stairs")