# 접근 방법 및 구현
# - 0으로 찬 삼각형 배열을 우선 정의
# - 시계 방향이므로 하 -> 우 -> 좌상으로 돌아가며 회전: 각 채우기 회차에서는 n회차 개의 값이 들어감
# - n회차 % 3 == 0이면 아래로 이동(x+1), n회차 % 3 == 1이면 우로 이동(y+1), 그 외에는 좌상으로 이동(x-1, y-1)

def solution(n):
    # 삼각형 배열
    answer = [[0 for j in range (1, i+1)] for i in range(1, n+1)]
    # 배열 위치
    x, y, num = -1, 0, 1
    for i in range(n):
        for j in range(i, n):
            # 아래로 이동
            if i % 3 == 0:
                x += 1
            # 오른쪽 이동
            elif i % 3 == 1:
                y += 1
            # 왼쪽 이동
            else:
                x -= 1
                y -= 1
            answer[x][y] = num
            num += 1
    return sum(answer, [])

# print(solution(4))