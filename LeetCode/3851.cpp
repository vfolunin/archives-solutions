class Solution {
public:
    int maxRequests(vector<vector<int>> &requests, int limit, int width) {
        unordered_map<int, vector<int>> times;
        for (vector<int> &request : requests)
            times[request[0]].push_back(request[1]);
        
        int res = requests.size();
        for (auto &[_, times] : times) {
            sort(times.begin(), times.end());
            deque<int> q;
            for (int time : times) {
                while (!q.empty() && q.front() + width < time)
                    q.pop_front();
                if (q.size() < limit)
                    q.push_back(time);
                else
                    res--;
            }
        }
        return res;
    }
};