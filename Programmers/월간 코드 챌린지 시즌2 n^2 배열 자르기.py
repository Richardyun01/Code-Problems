# 접근 방법 및 구현
# - 배열의 좌표가 (i, j)일 때 해당 요소의 값은 좌표에서 가장 큰 값
# - 배열 크기 n, 좌표 순서 m이 주어졌을 때 2차원 배열에서 1차원 인덱스를 행렬 좌표로 변환하는 경우:
#   - 행: 인덱스가 배열 크기 n을 몇 번 넘어갔는지 = 몫 n/m
#   - 열: 행 안에서 몇 번째 위치인지 = 나머지 n%m
#   - 여기에 1부터 시작하므로 +1을 붙이기

def solution(n, left, right):
    answer = []
    for i in range(left, right+1):
        answer.append(max(i // n, i % n) + 1)
    return answer