# ���� ��� �� ����
# - �־��� ���� k�������� ��ȯ
# - 0�� �������� ���� �и�
# - ���ڿ��� ���� ��ȯ�� �ش� ���� �Ҽ����� �Ǻ�
# - ���� 0, 1, �����̸� continue�� �ǳʶٱ�

def solution(n, k):
    answer = 0
    new_num = ''
    while n:
        new_num += str(n % k)
        n //= k
    new_num = new_num[::-1]
    # ã�� �Ҽ��� 10���� ����
    new_num = new_num.split('0')
    for i in new_num:
        # ���� ���̰� 0�̸� �н�
        if len(i) == 0:
            continue
        # ���� ���̰� 2 �̸��̸� �н�
        if int(i) < 2:
            continue
        # ���� �Ҽ����� �Ǻ�
        is_prime = True
        for j in range(2, int(int(i)**0.5)+1):
            if int(i) % j == 0:
                is_prime = False
                break
        if is_prime:
            answer += 1
    return answer