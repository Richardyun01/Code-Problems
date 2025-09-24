# 접근 방법 및 구현
# - 딕셔너리를 사용해 단어와 숫자를 일대일 대응
# - 딕셔너리 내의 값도 문자열로 저장
# - 전부 문자열이므로 문장이 완성된 뒤에 int로 변환

def solution(s):
    nums = {'zero': '0', 'one': '1', 'two': '2', 'three': '3', 'four': '4', 'five': '5', 'six': '6', 'seven': '7', 'eight': '8', 'nine': '9'}
    for key, value in nums.items():
        s = s.replace(key, value)
    return int(s)