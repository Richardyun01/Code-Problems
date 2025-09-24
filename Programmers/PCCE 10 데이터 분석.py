# ���� ��� �� ����
# - �÷� ������ ��ųʸ� ���·� �����ϴ� ���� �ʿ� -> �����Ϳ��� Ư�� ���� ����
# - data�� �ִ� ��� ���Ҹ� Ȯ���ϰ� ext�� val_ext���� ���� �������� ��쿡�� answer ����Ʈ�� append
# - ���� ������ �Ǵ� ���� �������� �����͸� �������� ����
# - ���ٽ����� sort_by�� ���� col_info�� ����

def solution(data, ext, val_ext, sort_by):
    answer = []
    # �÷� ����
    col_info = {
        "code": 0,
        "date": 1,
        "maximum": 2,
        "remain": 3
    }
    # ext ���� val_ext���� ���� �����͸� ȹ��
    for i in data:
        if i[col_info[ext]] < val_ext:
            answer.append(i)
    # sort_by �÷� �������� �������� ����
    answer.sort(key=lambda x: x[col_info[sort_by]])
    return answer