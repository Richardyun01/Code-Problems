class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for (int s : students) {
            q.push(s);
        }
        int moved = 0, idx = 0;
        while (q.size() && moved < q.size()) {
            if (q.front() == sandwiches[idx]) {
                q.pop();
                moved = 0;
                idx += 1;
            } else {
                q.push(q.front());
                q.pop();
                moved += 1;
            }
        }
        return q.size();
    }
};