# ���� ��� �� ����
# - s�� 1�� �� ������ �Ϸ��� ������ �ݺ�
# - s�� ��ȯ�� �߰� ���� x(0�� ��� ������ s)�� ���̸� �ʿ��ϹǷ� ���������� ���� �ʿ䰡 ����
# - ��� c�� ���̸� ���ϱ� ���� ���� ���ڿ��� 0�� ������ ���ؾ� ��(count �Լ�)

def solution(s):
    zeros = 0
    transform = 0
    while s != '1':
        zeros_cur = s.count('0')
        zeros += zeros_cur
        # x�� ����
        c = len(s) - zeros_cur
        # 2���� ��ȯ
        s = bin(c)[2:]
        transform += 1
    return [transform, zeros]