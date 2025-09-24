# 접근 방법 및 구현
# - 이모티콘 정가와 할인율을 dfs으로 탐색하여 조합
# - 깊이가 이모티콘 갯수와 같아질 때까지 할인율을 가져와 배열에 추가해 조합 생성
# - 깊이 == 이모티콘 갯수일 시 조합 배열 저장
# - 조합 하나를 저장한 후 깊이를 줄여 새로운 조합 배열 생성
# - 각 할인율 조합에 대한 플러스 유저 수와 이익을 각각 정의
# - 원하는 할인율 이상일 때만 이모티콘 구매
# - 아닐 시 플러스 유저 수 증가

def solution(users, emoticons):
    answer = [0, 0]
    data = [10, 20, 30, 40]
    discount = []
    # 이모티콘 정가와 할인율을 조합
    def dfs(tmp, depth):
        # 모든 이모티콘의 할인율이 정해질 시 조합 생성
        if depth == len(tmp):
            discount.append(tmp[:])
            return
        # 각 이모티콘이 가능한 할인율
        for d in data:
            tmp[depth] += d
            dfs(tmp, depth+1)
            tmp[depth] -= d
    dfs([0]*len(emoticons), 0)
    # 생성된 모든 할인율 조합에 시뮬레이션
    for d in range(len(discount)):
        plus_user = 0
        profit = 0
        for user in users:
            emoticon_buy = 0
            for i in range(len(emoticons)):
                # 할인 기준보다 크거나 같을 때 구매
                if discount[d][i] >= user[0]:
                    emoticon_buy += emoticons[i] * ((100 - discount[d][i]) / 100)
            # 한계 금액 이상일 시 플러스 가입
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