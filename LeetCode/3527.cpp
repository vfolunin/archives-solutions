class Solution {
public:
    string findCommonResponse(vector<vector<string>> &a) {
        map<string, int> count;
        int maxCount = 0;

        for (vector<string> &row : a)
            for (const string &s : unordered_set<string>(row.begin(), row.end()))
                maxCount = max(maxCount, ++count[s]);
        
        for (auto &[s, count] : count)
            if (count == maxCount)
                return s;
        return "";
    }
};