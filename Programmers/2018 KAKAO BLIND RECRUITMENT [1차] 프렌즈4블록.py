# 접근 방법 및 구현
# - 문자열을 2중 배열로 변환하여 인덱스 접근 및 수정할 수 있도록 변환
# - 조건을 만족하는 경우 임시 filter를 통해 체크를 하고 갯수를 센 뒤 터뜨리기
# - 블록 밑이 0이고 0이 아닌 것이 나오거나 바닥이 나올 때까지 값을 올려가면서 블록을 내림

def check(m, n, board):
    filter = [[0 for _ in range(n)] for _ in range(m)]
    cnt = 0
    # 터뜨릴 수 있는지 확인
    for i in range(m-1):
        for j in range(n-1):
            a = board[i][j]
            b = board[i][j+1]
            c = board[i+1][j]
            d = board[i+1][j+1]
            if a == b == c == d and a != '0':
                filter[i][j], filter[i][j+1], filter[i+1][j], filter[i+1][j+1] = 1, 1, 1, 1
    # 터뜨리기
    for i in range(m):
        for j in range(n):
            if filter[i][j] == 1:
                cnt += 1
                board[i][j] = '0'
    if cnt == 0:
        return 0
    # 공백 채우기(밑으로 내리기)
    for i in range(m-2, -1, -1):
        for j in range(n):
            k = i
            while 0 <= k+1 < m and board[k+1][j] == '0':
                k += 1
            if k != i:
                board[k][j] = board[i][j]
                board[i][j] = '0'
    return cnt

def solution(m, n, board):
    answer = 0
    board = list(map(list, board))
    while True:
        tmp = check(m, n, board)
        if tmp == 0:
            break
        answer += tmp
    return answer