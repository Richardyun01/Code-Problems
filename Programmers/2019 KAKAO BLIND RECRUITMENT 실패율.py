# ���� ��� �� ����
# - ������������ �� ū ���ڰ� ������ �� �н��� �����ϰ� ��ŵ
# - ���� �� ���� �ε����� ���ϱ� ���� ���� ���� �ε����� ���� ������ �����ϴ� ������ ����Ʈ �����ؾ� ��
# - ���� �������� �����ؾ� �ϹǷ� sort�� Ű�� ���ٽ��� ����ؾ� ��
# - ���ĵ� ����Ʈ�� �ε����� ����

def solution(N, stages):
    answer = []
    stage_cnt = []
    stage_check = []
    for i in range(N):
        stage_cnt.append(0)
    for stage in stages:
        if stage > N:
            continue
        else:
            stage_cnt[stage-1] += 1
    total = len(stages)
    for i in range(len(stage_cnt)):
        tmp = total
        # ������ �����ؾ� �ε��� Ȯ�� ����, 0���� ���������� ��� ����
        stage_check.append((i, stage_cnt[i] / tmp if tmp > 0 else 0))
        total -= stage_cnt[i]
    # �� ���� �������� ����
    stage_check.sort(key=lambda x: (-x[1], x[0]))
    # print(stage_check)
    # ���ĵ� ����Ʈ�� ���� �ε�����
    answer = [i+1 for i, _ in stage_check]
    return answer