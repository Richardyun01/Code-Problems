# 접근 방법 및 구현
# - 성격 유형에 대한 점수를 딕셔너리로 만들어 저장
# - 이를 재사용할 시 딕셔너리의 키만을 가져오는 리스트를 만들어 사용
# - for-if문만 사용해서 구현하는 것도 가능하지만 코드가 비효율적이게 되므로 비추천

def solution(survey, choices):
    answer = ''
    # 성격 유형 딕셔너리
    types = {'R': 0, 'T': 0, 'C': 0, 'F': 0, 'J': 0, 'M': 0, 'A': 0, 'N': 0}
    for i in range(len(choices)):
        # 1~3: 앞의 성격 유형
        if choices[i] < 4:
            types[survey[i][0]] += 4-choices[i]
        # 5~7: 뒤의 성격 유형
        elif choices[i] > 4:
            types[survey[i][1]] += choices[i]-4
    # 성격 유형만 가져오기
    type_key = list(types.keys())
    for i in range(0, len(type_key), 2):
        if types[type_key[i]] >= types[type_key[i+1]]:
            answer += type_key[i]
        elif types[type_key[i]] < types[type_key[i+1]]:
            answer += type_key[i+1]
        
    return answer