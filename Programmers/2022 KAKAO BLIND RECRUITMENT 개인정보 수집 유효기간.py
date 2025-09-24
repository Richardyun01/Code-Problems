# 접근 방법 및 구현
# - 오늘 날짜를 리스트로 변환
# - 약관 종류와 개월 수를 딕셔너리로 저장 후 한달을 곱함
# - 수집정보 중 날짜와 대상을 분리하고 날짜를 리스트로 변환
# - 연도, 월, 일을 각각 저장하고 일수를 곱해서 전체 일수 계산

def solution(today, terms, privacies):
    d = {}
    answer = []
    # 오늘 날짜 리스트로 변환
    today_list = list(map(int, today.split('.')))
    
    # 약관종류와 개월수 딕셔너리로 저장
    for term in terms:
        n, m = term.split()
        d[n] = int(m)*28
        
    for i in range(len(privacies)):
        date, s = privacies[i].split()
        # 수집일자 리스트로 변환
        date_list = list(map(int, date.split('.')))
        # 연도 차이에 일 수 곱하기
        year = (today_list[0] - date_list[0])*336
        # 달 차이에 일 수 곱하기
        month = (today_list[1] - date_list[1])*28
        day = today_list[2] - date_list[2]
        total = year + month + day
        if d[s] <= total:
            answer.append(i+1)
    return answer