class Solution {
public:
    vector<string> mostVisitedPattern(vector<string> &user, vector<int> &time, vector<string> &site) {
        unordered_map<string, vector<pair<int, string>>> visits;
        for (int i = 0; i < user.size(); i++)
            visits[user[i]].push_back({ time[i], site[i] });
        
        map<vector<string>, unordered_set<string>> patterns;
        for (auto &[user, visits] : visits) {
            sort(visits.begin(), visits.end());
            for (int ai = 0; ai < visits.size(); ai++)
                for (int bi = ai + 1; bi < visits.size(); bi++)
                    for (int ci = bi + 1; ci < visits.size(); ci++)
                        patterns[{ visits[ai].second, visits[bi].second, visits[ci].second }].insert(user);
        }

        int resScore = 0;
        vector<string> res;
        for (auto &[pattern, users] : patterns) {
            if (resScore < users.size()) {
                resScore = users.size();
                res = pattern;
            }
        }
        return res;
    }
};