# ���� ��� �� ����
# - ��ǥ Ž��: ¦�� ���� ��->��, Ȧ�� ���� ��->�� �������� Ž��
# - ������ �ٿ��� ������ �ʿ��� ���(���� �Ұ����� ������ ��)�� ó���� ������ �ʿ�
# - �� ��ǥ�� y ���̿� �������� ���ϰ� �������� ������ ���� ��ȯ

def solution(n, w, num):
    # �迭���� ��ȣ�� ��ǥ�� ��ȯ
    def find_coor(num):
        num -= 1
        y = num // w
        if y % 2 == 0:
            x = num % w
        else:
            x = w - num % w - 1
        return x, y
    # num�� n�� ��ǥ
    num_x, num_y = find_coor(num)
    n_x, n_y = find_coor(n)
    last_line = 0
    # n�� ¦�� �ٿ� ���� ��
    if n_y % 2 == 0:
        # n�� num �Ʒ��� x�� �� �����ʿ� ���� ��
        if n_y > num_y and num_x > n_x:
            last_line = -1
    # n�� Ȧ�� �ٿ� ���� ��
    else:
        # n�� num �Ʒ��� x�� �� ���ʿ� ���� ��
        if n_y > num_y and num_x < n_x:
            last_line = -1
    # ������ ����
    return n_y - num_y + last_line + 1