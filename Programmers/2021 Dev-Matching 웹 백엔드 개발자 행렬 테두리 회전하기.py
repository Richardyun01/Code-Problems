# 접근 방법 및 구현
# - r * c 행렬을 생성한 다음 초기화: 이 때 해당 행렬은 전역이어야 회전에 용이
# - 현재 값과 변화시킬 최소값을 저장할 임시 변수 정의
# - 첫 최소값은 시작점(가장 좌측 상단에 위치한 점)이 가장 작음으로 해당 값으로 설정
# - 상단 행 회전: 좌->우 값을 교체
# - 우측 열 회전: 상->하 값을 교체
# - 하단 행 회전: 우->좌 값을 교체
# - 좌측 열 회전: 하->상 값을 교체

def rotate(x1, y1, x2, y2):
    global matrix
    tmp1 = 0
    # 시작점 값
    tmp2 = matrix[x1][y1-1]
    # 회전하면서 최소값 추적(시작점이 가장 작음)
    min_num = tmp2
    # 상단 행 회전(좌->우)
    for i in range(y1, y2):
        tmp1 = matrix[x1-1][i-1]
        matrix[x1-1][i-1] = tmp2
        tmp2 = tmp1
        if tmp2 < min_num:
            min_num = tmp2
    # 우측 열 회전(상->하)
    for i in range(x1, x2):
        tmp1 = matrix[i-1][y2-1]
        matrix[i-1][y2-1] = tmp2
        tmp2 = tmp1
        if tmp2 < min_num:
            min_num = tmp2
    # 하단 행 회전(우->좌)
    for i in reversed(range(y1, y2)):
        tmp1 = matrix[x2-1][i]
        matrix[x2-1][i] = tmp2
        tmp2 = tmp1
        if tmp2 < min_num:
            min_num = tmp2
    # 좌측 열 회전(하->상)
    for i in reversed(range(x1, x2)):
        tmp1 = matrix[i][y1-1]
        matrix[i][y1-1] = tmp2
        tmp2 = tmp1
        if tmp2 < min_num:
            min_num = tmp2
    return min_num

def solution(rows, columns, queries):
    answer = []
    global matrix
    matrix = []
    num = 1
    # 행렬 초기화
    for i in range(rows):
        matrix.append([])
        for j in range(columns):
            matrix[i].append(num)
            num += 1
    # 회전 수행
    for query in queries:
        answer.append(rotate(query[0], query[1], query[2], query[3]))
    return answer
    
# print(solution(6, 6, [[2,2,5,4],[3,3,6,6],[5,1,6,3]]))
# print(solution(100, 97, [[1,1,100,97]]))