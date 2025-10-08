# ���� ��� �� ����
# - ��ųʸ��� �̿��ؼ� 10~15�� �빮�ڷ� ��ȯ
# - �Էµ� ���� ���� n���� ���� �������� ���Ͽ� �ӽ� ���ڿ��� �����ϰ� ������ return
# - ��ü ���ڿ��� ��ȯ�ϰ� ���̸�ŭ �ݺ��Ͽ� answer�� �� ���ڿ��� ����

# n���� ��ȯ �Լ�
def convert(num, n):
    # �� �빮�� ��ȯ
    nums = {10:'A', 11:'B', 12:'C', 13:'D', 14:'E', 15:'F'}
    tmp = ''
    if num == 0:
       return '0'
    # ���ڿ� ��ȯ
    while num:
        if num % n >= 10:
            tmp += nums[num % n]
        else:
            tmp += str(num % n)
        num //= n
    # ���ڿ� ������
    return tmp[::-1]

def solution(n, t, m, p):
    answer = ''
    tmp = ''
    # ��ȯ
    for i in range(t*m):
        tmp += convert(i, n)
    i = p-1
    # ���ڿ� ���̰� t�� �� ������ �ݺ�
    while i < len(tmp):
        if len(answer) == t:
            break
        answer += tmp[i]
        i += m
    return answer