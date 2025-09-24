# ���� ��� �� ����
# - �̸�Ƽ�� ������ �������� dfs���� Ž���Ͽ� ����
# - ���̰� �̸�Ƽ�� ������ ������ ������ �������� ������ �迭�� �߰��� ���� ����
# - ���� == �̸�Ƽ�� ������ �� ���� �迭 ����
# - ���� �ϳ��� ������ �� ���̸� �ٿ� ���ο� ���� �迭 ����
# - �� ������ ���տ� ���� �÷��� ���� ���� ������ ���� ����
# - ���ϴ� ������ �̻��� ���� �̸�Ƽ�� ����
# - �ƴ� �� �÷��� ���� �� ����

def solution(users, emoticons):
    answer = [0, 0]
    data = [10, 20, 30, 40]
    discount = []
    # �̸�Ƽ�� ������ �������� ����
    def dfs(tmp, depth):
        # ��� �̸�Ƽ���� �������� ������ �� ���� ����
        if depth == len(tmp):
            discount.append(tmp[:])
            return
        # �� �̸�Ƽ���� ������ ������
        for d in data:
            tmp[depth] += d
            dfs(tmp, depth+1)
            tmp[depth] -= d
    dfs([0]*len(emoticons), 0)
    # ������ ��� ������ ���տ� �ùķ��̼�
    for d in range(len(discount)):
        plus_user = 0
        profit = 0
        for user in users:
            emoticon_buy = 0
            for i in range(len(emoticons)):
                # ���� ���غ��� ũ�ų� ���� �� ����
                if discount[d][i] >= user[0]:
                    emoticon_buy += emoticons[i] * ((100 - discount[d][i]) / 100)
            # �Ѱ� �ݾ� �̻��� �� �÷��� ����
            if user[1] <= emoticon_buy:
                plus_user += 1
            else:
                profit += emoticon_buy
        if answer[0] < plus_user:
            answer = [plus_user, int(profit)]
        elif answer[0] == plus_user:
            if answer[1] < profit:
                answer = [plus_user, int(profit)]
    
    return answer