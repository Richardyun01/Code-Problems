# ���� ��� �� ����
# - ������ �������տ� ���� ����Ʈ�� ���� ����: �ҹ��ڷ� ���Ͻ�Ų �� �յ� �� ���ڰ� ���ĺ��� ��쿡�� ����
# - �� ��° ����Ʈ �ȿ� ù ����Ʈ�� �ܾ ���� ��� ���絵�� ������Ű�� �ش� ����Ʈ���� �ܾ� ����
# - ������=��ü �ܾ��� ���� ù ����Ʈ �ܾ� �� + �ߺ��� ������ �� ��° ����Ʈ �ܾ� ��

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