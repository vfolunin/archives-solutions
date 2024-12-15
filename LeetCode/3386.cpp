class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>> &events) {
        vector<int> time(1e5 + 1);
        for (int i = 0; i < events.size(); i++)
            time[events[i][0]] = max(time[events[i][0]], i ? events[i][1] - events[i - 1][1] : events[i][1]);
        return max_element(time.begin(), time.end()) - time.begin();
    }
};