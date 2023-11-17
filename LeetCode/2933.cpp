class Solution {
    int parseTime(const string &s) {
        return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(2));
    }

public:
    vector<string> findHighAccessEmployees(vector<vector<string>> &pairs) {
        map<string, vector<int>> times;
        for (vector<string> &pair : pairs)
            times[pair[0]].push_back(parseTime(pair[1]));
        
        vector<string> res;
        for (auto &[id, times] : times) {
            sort(times.begin(), times.end());

            for (int i = 0; i + 2 < times.size(); i++) {
                if (times[i] + 60 > times[i + 2]) {
                    res.push_back(id);
                    break;
                }
            }
        }

        return res;
    }
};