# ���� ��� �� ����
# - ��� ���ĺ�(��ū)�� ������ �ʱ� ���� letters�� ����
# - ���� ���� ���ڿ����� ���ڿ��� ���� �� ���ξ ������ �ִ���(��ġ�ϴ���) �������� Ž��
# - ���� ã�� ���� �� ���ξ��� ���� �ε����� ����� �߰�
# - �ش� ���ξ �� ���� ���� �ϳ��� ���� ���ڿ��� ������ ���(����� �ܾ�+���� ���ڸ� �� ��ū���� �߰�)

def solution(msg):
    answer = []
    # üũ�� ���� �ʴ� ��츦 �����ϱ� ���� ���� ������ ���� �߰�
    msg += '_'
    # print(msg)
    letters = list('_ABCDEFGHIJKLMNOPQRSTUVWXYZ')
    while len(msg) > 1:
        i = 0
        while msg[:-i] not in letters:
            i += 1
            # print(i)
        answer += [letters.index(msg[:-i])]
        # print(answer)
        letters += [msg[:-i+1]]
        # print(letters)
        # ���� �� �ܾ� üũ ���� ���� Ž��
        msg = msg[-i:]
        # print(msg)
    return answer