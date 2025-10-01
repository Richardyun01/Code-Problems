# 접근 방법 및 구현
# - 간단한 리스트-문자열 조작 문제
# - 이진법 변환은 bin()[2:] 함수 사용으로 해결 가능: 문자열 길이 맞추기 위해 더 짧은 경우 앞에다 '0' 붙이기

def solution(n, arr1, arr2):
    answer = []
    map1 = []
    map2 = []
    for i in range(n):
        bin_tmp = bin(arr1[i])[2:]
        if len(bin_tmp) != n:
            while len(bin_tmp) < n:
                bin_tmp = '0' + bin_tmp
        map1.append(bin_tmp)
    for i in range(n):
        bin_tmp = bin(arr2[i])[2:]
        if len(bin_tmp) != n:
            while len(bin_tmp) < n:
                bin_tmp = '0' + bin_tmp
        map2.append(bin_tmp)
    for a, b in zip(map1, map2):
        string_tmp = ''
        for i in range(n):
            if a[i] == '0' and b[i] == '0':
                string_tmp += ' '
            else:
                string_tmp += '#'
        answer.append(string_tmp)
    return answer