# ���� ��� �� ����
# - ���� ���� ����
# - ���� ������ ����ϱ� ���ٴ� ����Ʈ �ȿ� ��Ƽ� �ѹ��� �ջ��ϴ� ���� ����
# - *�� 2�� ������ ��� 2*2 = 4�̹Ƿ� ���� �˰����� ����� �� ���� �� �� �ߵ��ϰ� ��
# - python �迭�� [-1]: ���� ��ġ

def solution(dartResult):
    answer = 0
    # ���� �������� ����Ʈ�� ����
    score = list()
    # �ӽ� ����
    num = ''
    for i in dartResult:
        if i == 'S':
            score.append(int(num))
            num = ''
        elif i == 'D':
            score.append(int(num)**2)
            num = ''
        elif i == 'T':
            score.append(int(num)**3)
            num = ''
        elif i == '*':
            # ù ���� ��ȸ�� �� ù ���� 2��
            if len(score) == 1:
                score[0] *= 2
            # �ƴϸ� ����� ���� ���� 2��
            else:
                score[-1] *= 2
                score[-2] *= 2
        # ���� ���� -1��
        elif i == '#':
            score[-1] *= -1
        # �ӽ� ���� ����
        else:
            num += i
    #     print(score)
    # print(score)
    answer = sum(score)
    return answer