# ���� ��� �� ����
# - ���ڿ��� 2�� �迭�� ��ȯ�Ͽ� �ε��� ���� �� ������ �� �ֵ��� ��ȯ
# - ������ �����ϴ� ��� �ӽ� filter�� ���� üũ�� �ϰ� ������ �� �� �Ͷ߸���
# - ��� ���� 0�̰� 0�� �ƴ� ���� �����ų� �ٴ��� ���� ������ ���� �÷����鼭 ����� ����

def check(m, n, board):
    filter = [[0 for _ in range(n)] for _ in range(m)]
    cnt = 0
    # �Ͷ߸� �� �ִ��� Ȯ��
    for i in range(m-1):
        for j in range(n-1):
            a = board[i][j]
            b = board[i][j+1]
            c = board[i+1][j]
            d = board[i+1][j+1]
            if a == b == c == d and a != '0':
                filter[i][j], filter[i][j+1], filter[i+1][j], filter[i+1][j+1] = 1, 1, 1, 1
    # �Ͷ߸���
    for i in range(m):
        for j in range(n):
            if filter[i][j] == 1:
                cnt += 1
                board[i][j] = '0'
    if cnt == 0:
        return 0
    # ���� ä���(������ ������)
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