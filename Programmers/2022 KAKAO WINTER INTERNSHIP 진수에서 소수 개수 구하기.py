# 접근 방법 및 구현
# - friends의 이름 순서대로 dictionary에 인덱스 저장 -> gifts에서 이름을 인덱스로 바꾸기 위함
# - 테이블에 받은 선물 내역과 선물 지수 저장
# - gifts에서 split을 사용해 준 사람과 받은 사람을 구분
# - 준 선물의 개수가 더 많을 경우 많은 쪽이 선물을 받음
# - 준 선물의 개수가 동일할 경우 선물 지수가 더 많은 쪽이 선물을 받음

def solution(friends, gifts):
    answer = 0
    n = len(friends)
    friend_dict = dict()
    for i in range(n):
        friend_dict[friends[i]] = i
    table = [[0]*n for _ in range(n)]
    # 주고 받은 선물 내역(선물 지수)
    gift_index = [0]*n
    for gift in gifts:
        # a: 준 사람/b: 받은 사람
        a, b = gift.split()
        idx1, idx2 = friend_dict[a], friend_dict[b]
        gift_index[idx1] += 1
        gift_index[idx2] -= 1
        table[idx1][idx2] += 1
    get_gift = [0]*n
    for i in range(n):
        for j in range(n):
            if i == j:
                continue
            # 준게 더 많을 경우
            if table[i][j] > table[j][i]:
                get_gift[i] += 1
            # 주고 받은게 같거나 둘 다 안주고 받았을 경우: 선물 하나 추가
            elif table[i][j] == table[j][i]:
                if gift_index[i] > gift_index[j]:
                    get_gift[i] += 1
    answer = max(get_gift)
    return answer