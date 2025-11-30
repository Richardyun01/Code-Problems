class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<pair<int, int>> stk;
        int prev_time = 0;
        for (string log : logs) {
            stringstream ss(log);
            string part;
            getline(ss, part, ':');
            int id = stoi(part);
            getline(ss, part, ':');
            string type = part;
            getline(ss, part, ':');
            int time = stoi(part);
            // cout << "id: " << id << " type: " << type << " time: " << time << endl;
            if (type == "start") {
                if (!stk.empty()) {
                    ans[stk.top().first] += time - prev_time;
                    // cout << "stack top: " << stk.top().first << endl;
                }
                stk.push({id, time});
                prev_time = time;
                // cout << "prev_time: " << prev_time << endl;
            } else {
                ans[stk.top().first] += time - prev_time+1;
                // cout << "stack top: " << stk.top().first << endl;
                stk.pop();
                prev_time = time+1;
                // cout << "prev_time: " << prev_time << endl;
            }
        }
        return ans;
    }
};