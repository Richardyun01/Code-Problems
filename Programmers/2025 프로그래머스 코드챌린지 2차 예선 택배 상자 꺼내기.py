# 접근 방법 및 구현
# - 좌표 탐색: 짝수 줄은 좌->우, 홀수 줄은 우->좌 방향으로 탐색
# - 마지막 줄에서 보정이 필요한 경우(도달 불가능한 마지막 줄)를 처리할 변수가 필요
# - 두 좌표의 y 차이에 보정값을 더하고 시작줄을 포함한 값을 반환

def solution(n, w, num):
    # 배열에서 번호를 좌표로 변환
    def find_coor(num):
        num -= 1
        y = num // w
        if y % 2 == 0:
            x = num % w
        else:
            x = w - num % w - 1
        return x, y
    # num과 n의 좌표
    num_x, num_y = find_coor(num)
    n_x, n_y = find_coor(n)
    last_line = 0
    # n이 짝수 줄에 있을 때
    if n_y % 2 == 0:
        # n이 num 아래고 x가 더 오른쪽에 있을 시
        if n_y > num_y and num_x > n_x:
            last_line = -1
    # n이 홀수 줄에 있을 때
    else:
        # n이 num 아래고 x가 더 왼쪽에 있을 시
        if n_y > num_y and num_x < n_x:
            last_line = -1
    # 시작줄 포함
    return n_y - num_y + last_line + 1