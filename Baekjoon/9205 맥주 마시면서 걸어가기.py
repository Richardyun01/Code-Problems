home_x, home_y = 0, 0
rock_x, rock_y = 0, 0
t = int(input())
vis = [False] * 101

def dfs(conv, now_x, now_y, rock_x, rock_y):
    conv_s = len(conv)
    # 현재 위치에서 목적지까지의 거리
    f_dist = abs(now_x - rock_x) + abs(now_y - rock_y)
    # 만약 목적지까지의 거리가 1000 이하면 바로 도달 가능
    if f_dist <= 1000:
        return True
    for i in range(conv_s):
        # 이미 방문한 경유지 패스
        if vis[i]:
            continue
        # 현재 위치에서 i번째 경유지가지의 거리
        conv_dist = abs(now_x - conv[i][0]) + abs(now_y - conv[i][1])
        # 거리가 1000을 넘으면 한 번에 갈 수 없으므로 패스
        if conv_dist > 1000:
            continue
        # 방문했으므로 방문 처리
        vis[i] = True
        # 해당 경유지로 이동한상태에서 다시 갈 수 있는지 재귀 탐색
        if dfs(conv, conv[i][0], conv[i][1], rock_x, rock_y):
            return True
    return False

for _ in range(t):
    conv = []
    n = int(input())
    home_x, home_y = map(int, input().split())
    for j in range(n):
        tmp1, tmp2 = map(int, input().split())
        conv.append((tmp1, tmp2))
    rock_x, rock_y = map(int, input().split())
    if dfs(conv, home_x, home_y, rock_x, rock_y):
        print("happy")
    else:
        print("sad")
    vis = [False] * 101