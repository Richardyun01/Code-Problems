# ���� ��� �� ����
# - �Է� ���̰� ª���Ƿ� ���� Ž�� ����
# - �Էµ� ���ڿ��� ������ �ִ� ���� ��ŭ�� Ž���Ͽ� ���� ����� ã���� ��
# - ���� ���� ���� 1���� ���������� �����Ͽ� �� ��츶�� �ݺ�
# - ���� ���ڿ��� ���°� ���� ���¿� ���� �� ���� ����, �׷��� ������ ���� �ʱ�ȭ

def solution(s):
    answer = len(s)
    for i in range(1, len(s)//2+1):
        comp = ''
        # 0���� i��ŭ�� ���ڿ� ����
        prev = s[0:i]
        cnt = 1
        # i��ŭ ũ�⸦ �������� ���� ���ڿ��� ��
        for j in range(i, len(s), i):
            # ���� ���¿� ���� �� ���� Ƚ�� ����
            if prev == s[j:j+i]:
                cnt += 1
            # �ٸ� ���ڿ�(���� �Ұ�)
            else:
                if cnt >= 2:
                    comp += str(cnt) + prev
                else:
                    comp += prev
                # ���� �ʱ�ȭ
                prev = s[j:j+i]
                cnt = 1
        # ���� ���ڿ� ó��
        if cnt >= 2:
            comp += str(cnt) + prev
        else:
            comp += prev
        # ���� ª�� ���ڿ� ����
        answer = min(answer, len(comp))
    return answer