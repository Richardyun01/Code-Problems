# 접근 방법 및 구현
# - id_list 순서대로 인덱스 부여: dictionary에 id/index(key/value) 저장
# - 신고 내역 report를 신고 현황용 2차원 배열 result에 저장
# - a가 b를 신고할 시 해당 신고 현황값을 1로 변경 -> a가 b를 여러 번 신고해도 1로 저장됨
# - 각 id별 신고 당한 횟수를 파악
# - 신고 당한 index를 파악하고 신고 내역 result 배열로 신고한 유저를 확인

def solution(id_list, report, k):
    n = len(id_list)
    answer = [0]*n
    id_dict = dict()
    for i in range(n):
        id_dict[id_list[i]] = i
    # 신고 현황 저장
    result = [[0]*n for _ in range(n)]
    for r in report:
        a, b = r.split()
        a_idx, b_idx = id_dict[a], id_dict[b]
        result[a_idx][b_idx] = 1
    # 신고당한 횟수 저장
    reported_time = [0]*n
    for j in range(n):
        for i in range(n):
            if result[i][j] != 0:
                reported_time[j] += 1
    # k번 이상 신고 당한 유저를 신고한 유저 탐색
    for j in range(n):
        # 신고 횟수 k번 이상인 경우
        if reported_time[j] >= k: 
            for i in range(n):
                if result[i][j] != 0:
                    answer[i] += 1
    return answer