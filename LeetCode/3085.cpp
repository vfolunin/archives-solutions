class Solution {
public:
    int minimumDeletions(string &s, int limit) {
        unordered_map<char, int> count;
        for (char c : s)
            count[c]++;
        
        vector<int> counts;
        for (auto &[c, count] : count)
            counts.push_back(count);
        sort(counts.begin(), counts.end());

        int res = 1e9;
        for (int i = 0; i < counts.size(); i++) {
            int cur = 0;
            for (int j = 0; j < counts.size(); j++) {
                if (counts[j] < counts[i])
                    cur += counts[j];
                else if (counts[i] + limit < counts[j])
                    cur += counts[j] - counts[i] - limit;
            }
            res = min(res, cur);
        }
        return res;
    }
};