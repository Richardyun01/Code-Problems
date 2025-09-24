# 접근 방법 및 구현
# - 컬럼 정보를 딕셔너리 형태로 저장하는 것이 필요 -> 데이터에서 특정 열에 접근
# - data에 있는 모든 원소를 확인하고 ext가 val_ext보다 작은 데이터인 경우에는 answer 리스트에 append
# - 정렬 기준이 되는 열을 기준으로 데이터를 오름차순 정렬
# - 람다식으로 sort_by에 따라 col_info를 정렬

def solution(data, ext, val_ext, sort_by):
    answer = []
    # 컬럼 정보
    col_info = {
        "code": 0,
        "date": 1,
        "maximum": 2,
        "remain": 3
    }
    # ext 값이 val_ext보다 작은 데이터만 획득
    for i in data:
        if i[col_info[ext]] < val_ext:
            answer.append(i)
    # sort_by 컬럼 기준으로 오름차순 정렬
    answer.sort(key=lambda x: x[col_info[sort_by]])
    return answer