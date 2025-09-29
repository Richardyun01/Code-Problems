# ���� ��� �� ����
# - �ٱ��ϴ� LIFO �����̹Ƿ� ������ ����ϸ� ��(���̽��� ����Ʈ�� ����)
# - ���ÿ��� ���� ������ �� ���� ������ �׿��� �� ���� -> �̶� ���� 2�� �Ҹ�
# - üũ ���� �� �ش� ���������� �� �� �ʿ䰡 �����Ƿ� break

def solution(board, moves):
    stk = []
    answer = 0
    for i in moves:
        for j in range(len(board)):
            if board[j][i-1] != 0:
                stk.append(board[j][i-1])
                board[j][i-1] = 0
                # ������ 2�� �̻� �׿��� �� �� 2���� ���� �� ����
                if len(stk) > 1:
                    if stk[-1] == stk[-2]:
                        # ���� 2�� �Ҹ�
                        stk.pop(-1)
                        stk.pop(-1)
                        answer += 2
                break
    return answer