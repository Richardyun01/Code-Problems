# 접근 방법 및 구현
# - 고른 로또 번호 중에서 당첨 번호와 일치하는 번호의 개수 카운트
# - 모르는 번호 0인 번호의 개수 카운트
# - 최저 랭킹과 zero+win인 최고 랭킹 계산

def calc_rank(cnt):
    if cnt < 2:
        return 6
    else:
        return 7 - cnt
    
def solution(lottos, win_nums):
    zero_cnt = win_cnt = 0
    # 일치하는 번호/모르는 번호
    for lotto in lottos:
        if lotto in win_nums:
            win_cnt += 1
        elif lotto ==  0:
            zero_cnt += 1
    # 최저/최고 랭킹
    min_rank = calc_rank(win_cnt)
    max_rank = calc_rank(win_cnt+zero_cnt)
    answer = [max_rank, min_rank]
    return answer