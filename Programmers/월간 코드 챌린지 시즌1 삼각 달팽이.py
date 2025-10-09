# ���� ��� �� ����
# - 0���� �� �ﰢ�� �迭�� �켱 ����
# - �ð� �����̹Ƿ� �� -> �� -> �»����� ���ư��� ȸ��: �� ä��� ȸ�������� nȸ�� ���� ���� ��
# - nȸ�� % 3 == 0�̸� �Ʒ��� �̵�(x+1), nȸ�� % 3 == 1�̸� ��� �̵�(y+1), �� �ܿ��� �»����� �̵�(x-1, y-1)

def solution(n):
    # �ﰢ�� �迭
    answer = [[0 for j in range (1, i+1)] for i in range(1, n+1)]
    # �迭 ��ġ
    x, y, num = -1, 0, 1
    for i in range(n):
        for j in range(i, n):
            # �Ʒ��� �̵�
            if i % 3 == 0:
                x += 1
            # ������ �̵�
            elif i % 3 == 1:
                y += 1
            # ���� �̵�
            else:
                x -= 1
                y -= 1
            answer[x][y] = num
            num += 1
    return sum(answer, [])

# print(solution(4))