# ���� ��� �� ����
# - ���� ������ ���� ������ ��ųʸ��� ����� ����
# - �̸� ������ �� ��ųʸ��� Ű���� �������� ����Ʈ�� ����� ���
# - for-if���� ����ؼ� �����ϴ� �͵� ���������� �ڵ尡 ��ȿ�����̰� �ǹǷ� ����õ

def solution(survey, choices):
    answer = ''
    # ���� ���� ��ųʸ�
    types = {'R': 0, 'T': 0, 'C': 0, 'F': 0, 'J': 0, 'M': 0, 'A': 0, 'N': 0}
    for i in range(len(choices)):
        # 1~3: ���� ���� ����
        if choices[i] < 4:
            types[survey[i][0]] += 4-choices[i]
        # 5~7: ���� ���� ����
        elif choices[i] > 4:
            types[survey[i][1]] += choices[i]-4
    # ���� ������ ��������
    type_key = list(types.keys())
    for i in range(0, len(type_key), 2):
        if types[type_key[i]] >= types[type_key[i+1]]:
            answer += type_key[i]
        elif types[type_key[i]] < types[type_key[i+1]]:
            answer += type_key[i+1]
        
    return answer