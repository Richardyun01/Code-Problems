# ���� ��� �� ����
# - id_list ������� �ε��� �ο�: dictionary�� id/index(key/value) ����
# - �Ű� ���� report�� �Ű� ��Ȳ�� 2���� �迭 result�� ����
# - a�� b�� �Ű��� �� �ش� �Ű� ��Ȳ���� 1�� ���� -> a�� b�� ���� �� �Ű��ص� 1�� �����
# - �� id�� �Ű� ���� Ƚ���� �ľ�
# - �Ű� ���� index�� �ľ��ϰ� �Ű� ���� result �迭�� �Ű��� ������ Ȯ��

def solution(id_list, report, k):
    n = len(id_list)
    answer = [0]*n
    id_dict = dict()
    for i in range(n):
        id_dict[id_list[i]] = i
    # �Ű� ��Ȳ ����
    result = [[0]*n for _ in range(n)]
    for r in report:
        a, b = r.split()
        a_idx, b_idx = id_dict[a], id_dict[b]
        result[a_idx][b_idx] = 1
    # �Ű���� Ƚ�� ����
    reported_time = [0]*n
    for j in range(n):
        for i in range(n):
            if result[i][j] != 0:
                reported_time[j] += 1
    # k�� �̻� �Ű� ���� ������ �Ű��� ���� Ž��
    for j in range(n):
        # �Ű� Ƚ�� k�� �̻��� ���
        if reported_time[j] >= k: 
            for i in range(n):
                if result[i][j] != 0:
                    answer[i] += 1
    return answer