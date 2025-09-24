# ���� ��� �� ����
# - ���� ū �ʿ��� pop�� �� �ٸ� �ʿ� �߰��ϸ� ��
# - queue�� ���̰� ����� ���� ���� �ҿ� �ð��� ������Ƿ� �̸� ������ ������ ��
# - �ִ� �̵� Ƚ���� �� ť�� ������ ��+2
# - �ִ� �̵� Ƚ���� �ʰ��� �� return�� �Ͽ� ������ ����� ��

from collections import deque

def solution(queue1, queue2):
    q1, q2 = deque(queue1), deque(queue2)
    sum1, sum2 = sum(q1), sum(q2)
    cnt = len(q1) + len(q2) + 2
    answer = 0
    # �� ť�� ���� Ȧ���� ������ ���� ���� �� ����
    if (sum1 + sum2) % 2 == 1:
        return -1
    # ������ ������ �ݺ�
    while sum1 != sum2:
        if cnt > 0:
            # ���� ū �ʿ��� ���Ҹ� pop�� �ٸ� �ʿ� �߰�
            if sum1 < sum2:
                i = q2.popleft()
                q1.append(i)
                sum1 += i
                sum2 -= i
                cnt -= 1
                answer += 1
            elif sum1 > sum2:
                i = q1.popleft()
                q2.append(i)
                sum1 -= i
                sum2 += i
                cnt -= 1
                answer += 1
        # �ִ� �̵� Ƚ�� �ʰ� �� return
        else:
            return -1
    return answer