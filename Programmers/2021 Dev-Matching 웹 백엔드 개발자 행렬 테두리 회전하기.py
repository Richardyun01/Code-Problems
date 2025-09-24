# ���� ��� �� ����
# - r * c ����� ������ ���� �ʱ�ȭ: �� �� �ش� ����� �����̾�� ȸ���� ����
# - ���� ���� ��ȭ��ų �ּҰ��� ������ �ӽ� ���� ����
# - ù �ּҰ��� ������(���� ���� ��ܿ� ��ġ�� ��)�� ���� �������� �ش� ������ ����
# - ��� �� ȸ��: ��->�� ���� ��ü
# - ���� �� ȸ��: ��->�� ���� ��ü
# - �ϴ� �� ȸ��: ��->�� ���� ��ü
# - ���� �� ȸ��: ��->�� ���� ��ü

def rotate(x1, y1, x2, y2):
    global matrix
    tmp1 = 0
    # ������ ��
    tmp2 = matrix[x1][y1-1]
    # ȸ���ϸ鼭 �ּҰ� ����(�������� ���� ����)
    min_num = tmp2
    # ��� �� ȸ��(��->��)
    for i in range(y1, y2):
        tmp1 = matrix[x1-1][i-1]
        matrix[x1-1][i-1] = tmp2
        tmp2 = tmp1
        if tmp2 < min_num:
            min_num = tmp2
    # ���� �� ȸ��(��->��)
    for i in range(x1, x2):
        tmp1 = matrix[i-1][y2-1]
        matrix[i-1][y2-1] = tmp2
        tmp2 = tmp1
        if tmp2 < min_num:
            min_num = tmp2
    # �ϴ� �� ȸ��(��->��)
    for i in reversed(range(y1, y2)):
        tmp1 = matrix[x2-1][i]
        matrix[x2-1][i] = tmp2
        tmp2 = tmp1
        if tmp2 < min_num:
            min_num = tmp2
    # ���� �� ȸ��(��->��)
    for i in reversed(range(x1, x2)):
        tmp1 = matrix[i][y1-1]
        matrix[i][y1-1] = tmp2
        tmp2 = tmp1
        if tmp2 < min_num:
            min_num = tmp2
    return min_num

def solution(rows, columns, queries):
    answer = []
    global matrix
    matrix = []
    num = 1
    # ��� �ʱ�ȭ
    for i in range(rows):
        matrix.append([])
        for j in range(columns):
            matrix[i].append(num)
            num += 1
    # ȸ�� ����
    for query in queries:
        answer.append(rotate(query[0], query[1], query[2], query[3]))
    return answer
    
# print(solution(6, 6, [[2,2,5,4],[3,3,6,6],[5,1,6,3]]))
# print(solution(100, 97, [[1,1,100,97]]))