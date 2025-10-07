# 접근 방법 및 구현
# - 각각의 다중집합에 대한 리스트를 따로 저장: 소문자로 통일시킨 뒤 앞뒤 두 문자가 알파벳인 경우에만 저장
# - 두 번째 리스트 안에 첫 리스트의 단어가 있을 경우 유사도를 증가시키고 해당 리스트에서 단어 제거
# - 합집합=전체 단어의 수는 첫 리스트 단어 수 + 중복을 제거한 두 번째 리스트 단어 수

def solution(str1, str2):
    answer = 0
    similar = 0
    all_words = 0
    list1, list2 = [], []
    str1 = str1.lower()
    str2 = str2.lower()
    # print(str1)
    # print(str2)
    for i in range(len(str1)-1):
        tmp = ''
        a, b = str1[i], str1[i+1]
        if a.isalpha() and b.isalpha():
            tmp += a+b
            list1.append(tmp)
    for i in range(len(str2)-1):
        tmp = ''
        a, b = str2[i], str2[i+1]
        if a.isalpha() and b.isalpha():
            tmp += a+b
            list2.append(tmp)
    # print(list1)
    # print(list2)
    for term in list1:
        if term in list2:
            similar += 1
            list2.remove(term)
    all_words = len(list1) + len(list2)
    # print(similar)
    # print(all_words)
    if all_words == 0:
        return 65536
    answer = int(similar / all_words * 65536)
    return answer
    
# print(solution("FRANCE", "france"))