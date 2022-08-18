class Solution {
    int parseTime(string &s) {
        stringstream ss(s);
        int h, m;
        char colon;
        ss >> h >> colon >> m;
        return h * 60 + m;
    }
    
public:
    vector<string> alertNames(vector<string> &name, vector<string> &time) {
        unordered_map<string, vector<int>> times;
        for (int i = 0; i < name.size(); i++)
            times[name[i]].push_back(parseTime(time[i]));
        
        vector<string> res;
        for (auto &[name, time] : times) {
            sort(time.begin(), time.end());
            for (int i = 0; i + 2 < time.size(); i++) {
                if (time[i] + 60 >= time[i + 2]) {
                    res.push_back(name);
                    break;
                }
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};