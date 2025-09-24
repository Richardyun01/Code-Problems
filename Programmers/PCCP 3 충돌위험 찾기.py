/*
  접근 방법 및 구현
  - 각 경로마다 이동 과정을 시뮬레이션
  - 1초에 한 칸씩 움직일 때마다 (x, y, 시간) 튜플을 생성해 리스트에 기록
  - 모든 경로에 대한 시뮬레이션 종료 후 각 경로에서 생성된 기록들을 second 리스트에 합침
  - 튜플이 전체 리스트에서 몇 번 중복되어 나타나는지 계산
  - 특정 튜플의 개수가 2개 이상이면 충돌로 간주
*/

from collections import Counter

def solution(points, routes):
    def bfs(route):
        idx = 0
        pa = []
        for i in range(len(route) - 1):
            # 출발지와 도착지의 좌표
            sx, sy = spots[route[i]-1]
            ex, ey = spots[route[i+1]-1]
            # x 좌표 맞추기
            while sx != ex:
                pa.append((sx, sy, idx))
                if sx < ex:
                    sx += 1
                else:
                    sx -= 1
                idx += 1
            # y 좌표 맞추기
            while sy != ey:
                pa.append((sx, sy, idx))
                if sy < ey:
                    sy += 1
                else:
                    sy -= 1
                idx += 1
        pa.append((sx, sy, idx))
        return pa
    
    spots = [i for i in points]
    second = []
    # 모든 경로에 대해 각 경로의 시뮬레이션 결과를 리스트에 추가
    for route in routes:
        second.extend(bfs(route))
    answer = 0
    tmp = Counter(second)
    # 등장 횟수가 2 이상일 시 충돌 1 증가
    for i in tmp.values():
        if i >= 2:
            answer += 1
    return answer