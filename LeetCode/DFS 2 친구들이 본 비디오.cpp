class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        queue<int> q({id});
        int total_people = friends.size();
        // 방문한 사람 기록
        vector<bool> vis(total_people);
        vis[id] = true;

        while (level--) {
            int cur_level = q.size();
            // 현재 레벨의 모든 사람들에 대해서
            for (int i = 0; i < cur_level; i++) {
                int cur_person = q.front();
                q.pop();
                // 방문하지 않은 친구라면 다음 레벨의 큐에 추가
                for (auto friend_id : friends[cur_person]) {
                    if (!vis[friend_id]) {
                        vis[friend_id] = true;
                        q.push(friend_id);
                    }
                }
            }
        }

        // 특정 레벨에서 모든 사람들이 본 비디오 수 세기
        unordered_map<string, int> video_frequency;
        while (!q.empty()) {
            int person = q.front();
            q.pop();
            // 특정 사람이 본 모든 비디오 수 세기
            for (auto video : watchedVideos[person]) {
                video_frequency[video]++;
            }
        }

        // 모든 비디오 종류를 세서 정리
        vector<string> res;
        for (const auto& [video, freq] : video_frequency) {
            res.push_back(video);
        }
        // 비디오를 시청 빈도와 알파벳 순서대로 정렬
        sort(res.begin(), res.end(), [&video_frequency](const string& vidA, const string& vidB) {
            // 빈도가 같을 시 알파벳 순으로 정렬
            if (video_frequency[vidA] == video_frequency[vidB]) {
                return vidA < vidB;
            }
            // 빈도 순으로 정렬
            return video_frequency[vidA] < video_frequency[vidB];
        });
        return res;
    }
};