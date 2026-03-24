class Solution:
    def watchedVideosByFriends(self, watchedVideos: List[List[str]], friends: List[List[int]], id: int, level: int) -> List[str]:
        q = deque([id])
        # 방문한 사람 기록
        vis = {id}

        for _ in range(level):
            # 현재 레벨의 모든 사람들에 대해서
            for _ in range(len(q)):
                cur = q.popleft()
                # 방문하지 않은 친구라면 다음 레벨의 큐에 추가
                for friend in friends[cur]:
                    if friend not in vis:
                        vis.add(friend)
                        q.append(friend)

        # 특정 레벨에서 모든 사람들이 본 비디오 수 세기
        cnt = Counter()
        for per_id in q:
            for video in watchedVideos[per_id]:
                cnt[video] += 1

        # 비디오를 수/알파벳 오름차순으로 정렬
        return sorted(cnt.keys(), key=lambda k: (cnt[k], k))