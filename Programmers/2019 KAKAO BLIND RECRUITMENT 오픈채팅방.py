# ���� ��� �� ����
# - ����� �̸��� ���¸� �����ϴ� ��ųʸ��� ����
# - �տ��� Enter �Ǵ� Change�� ���(����ڰ� ���ŵǴ� ���) ��ųʸ��� ����
# - ������ �̸��� ���� Enter �Ǵ� Leave�� ��� ������ �°� ���

def solution(record):
    answer = []
    users = {}
    for rec in record:
        i = rec.split()
        if i[0] in ['Enter', 'Change']:
            users[i[1]] = i[2]
    for rec in record:
        i = rec.split()
        if i[0] == 'Enter':
            answer.append(users[i[1]]+'���� ���Խ��ϴ�.')
        elif i[0] == 'Leave':
            answer.append(users[i[1]]+'���� �������ϴ�.')
    return answer