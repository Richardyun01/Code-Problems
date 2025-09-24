# ���� ��� �� ����
# - �� �ð��뺰 ������ ������ ���� ����س��ƾ� ��
# - 24�ð� ���� 
#   - ���� �ʿ��� ������ ���� Ȯ��
#   - ���� �ʿ��� ������ ���� ������ ������ ������ ũ��
#   - �����ؾ� �ϴ� Ƚ���� ���
#   - �̸� �׻� ����
#   - ������ ������ k�ð� ���� �����ǵ��� ��

def solution(players, m, k):
    # ������ ������ ��
    added_server = [0]*24
    answer = 0
    for i in range(24):
        # �ʿ��� ������ ��
        p = players[i] // m
        # �ʿ��� ������ ���� ������ ������ ������ ũ��
        if p > added_server[i]:
            # ���� Ƚ��
            tmp = p - added_server[i]
            # �̸� �׻� �����ϵ��� ��
            answer += tmp
            # k�ð� ���� �ѵα�
            if i + k < 24:
                for j in range(i, i+k):
                    added_server[j] += tmp
            else:
                for j in range(i, 24):
                    added_server[j] += tmp
    return answer