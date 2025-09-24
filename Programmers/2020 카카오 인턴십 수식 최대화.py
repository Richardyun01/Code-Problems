# ���� ��� �� ����
# - ������ �켱���� ����� ���� 6������ ������ ���̵� ª���Ƿ� ���Ʈ������ ���
# - �Ľ����� ���Ŀ��� ���ڿ� �����ڸ� �и�
# - permutations�� ������ �켱���� 6������ ��� ����
# - �� �켱�������� ���� �Ľ��� ������ ���Ŀ��� ���� �����ڸ� �ϳ��� �ٿ����� ���� ��� ����
# - ������ ���� �����ϰ� max�� �ִ� ȹ��

from itertools import permutations

def solution(expression):
    # �� �� ��ȣ �Ľ�
    def parse(expr):
        nums, ops, cur = [], [], ""
        for ch in expr:
            # ���ڸ� ���� ���ڿ� �̾����
            if '0' <= ch <= '9':
                cur += ch
            # �����ڸ� ��/������ ����Ʈ�� �߰�
            else:
                nums.append(int(cur))
                ops.append(ch)
                cur = ""
        # ������ ����
        nums.append(int(cur))
        return nums, ops
    
    values = []
    for priority in permutations(['*', '+', '-'], 3):
        # �����ڿ� �ǿ����� ����
        operands, operators = parse(expression)
        for op in priority:
            while op in operators:
                # i��° �����ڴ� i��°�� i+1��° �ǿ����ڿ� ���� ��� ����
                i = operators.index(op)
                if op == '*':
                    v = operands[i] * operands[i+1]
                elif op == '+':
                    v = operands[i] + operands[i+1]
                else:
                    v = operands[i] - operands[i+1]
                # ������/�ǿ����� ����Ʈ ������Ʈ
                operands[i] = v
                operands.pop(i+1)
                operators.pop(i)
            values.append(operands[0])
    return max(abs(v) for v in values)