# ���� ��� �� ����
# - �� �ζ� ��ȣ �߿��� ��÷ ��ȣ�� ��ġ�ϴ� ��ȣ�� ���� ī��Ʈ
# - �𸣴� ��ȣ 0�� ��ȣ�� ���� ī��Ʈ
# - ���� ��ŷ�� zero+win�� �ְ� ��ŷ ���

def calc_rank(cnt):
    if cnt < 2:
        return 6
    else:
        return 7 - cnt
    
def solution(lottos, win_nums):
    zero_cnt = win_cnt = 0
    # ��ġ�ϴ� ��ȣ/�𸣴� ��ȣ
    for lotto in lottos:
        if lotto in win_nums:
            win_cnt += 1
        elif lotto ==  0:
            zero_cnt += 1
    # ����/�ְ� ��ŷ
    min_rank = calc_rank(win_cnt)
    max_rank = calc_rank(win_cnt+zero_cnt)
    answer = [max_rank, min_rank]
    return answer