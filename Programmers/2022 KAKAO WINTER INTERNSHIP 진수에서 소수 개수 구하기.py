# ���� ��� �� ����
# - friends�� �̸� ������� dictionary�� �ε��� ���� -> gifts���� �̸��� �ε����� �ٲٱ� ����
# - ���̺� ���� ���� ������ ���� ���� ����
# - gifts���� split�� ����� �� ����� ���� ����� ����
# - �� ������ ������ �� ���� ��� ���� ���� ������ ����
# - �� ������ ������ ������ ��� ���� ������ �� ���� ���� ������ ����

def solution(friends, gifts):
    answer = 0
    n = len(friends)
    friend_dict = dict()
    for i in range(n):
        friend_dict[friends[i]] = i
    table = [[0]*n for _ in range(n)]
    # �ְ� ���� ���� ����(���� ����)
    gift_index = [0]*n
    for gift in gifts:
        # a: �� ���/b: ���� ���
        a, b = gift.split()
        idx1, idx2 = friend_dict[a], friend_dict[b]
        gift_index[idx1] += 1
        gift_index[idx2] -= 1
        table[idx1][idx2] += 1
    get_gift = [0]*n
    for i in range(n):
        for j in range(n):
            if i == j:
                continue
            # �ذ� �� ���� ���
            if table[i][j] > table[j][i]:
                get_gift[i] += 1
            # �ְ� ������ ���ų� �� �� ���ְ� �޾��� ���: ���� �ϳ� �߰�
            elif table[i][j] == table[j][i]:
                if gift_index[i] > gift_index[j]:
                    get_gift[i] += 1
    answer = max(get_gift)
    return answer