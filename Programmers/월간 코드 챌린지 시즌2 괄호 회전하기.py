# ���� ��� �� ����
# - ���ڿ� ȸ��(�����̽�)�� ���� 2���� �̾����
# - ��� ȸ�� ���ڿ��� �����Ͽ� �� ȸ���� ���� �ùٸ� ��ȣ ���ڿ����� �˻�
# - ¦�� ���� ������ ���ÿ� �ְ� ������� ���� ���� ���ڿ�

def solution(s):
    answer = 0
    # ���ڿ��� ȸ����ų �� �ֵ��� 2��� �����
    circle = s*2
    for i in range(len(s)):
        # ���� ��ġ���� ���̸�ŭ ���ڿ� ����
        sub = circle[i:i+len(s)]
        stack = []
        for j in sub:
            # ������ ������� ��
            if not stack:
                stack.append(j)
                continue
            # ������ ������ ���ҿ� ���� ��ȣ�� ¦�� �̷�� ��� pop
            if ((stack[-1] == '(' and j == ')') or
                (stack[-1] == '{' and j == '}') or
                (stack[-1] == '[' and j == ']')):
                    stack.pop()
            # ¦�� �ȸ�����
            else:
                stack.append(j)
        if not stack:
            answer += 1
    return answer