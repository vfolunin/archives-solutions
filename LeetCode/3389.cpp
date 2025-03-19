class Solution {
    int rec(vector<int> &count, int targetCount, int i, int deletedCount, vector<vector<int>> &memo) {
        if (i == count.size())
            return 0;
        
        int &res = memo[i][deletedCount];
        if (res != -1)
            return res;
        
        if (count[i] > targetCount)
            return res = rec(count, targetCount, i + 1, count[i] - targetCount, memo) + count[i] - targetCount;
        else
            return res = min(rec(count, targetCount, i + 1, count[i], memo) + count[i],
                             rec(count, targetCount, i + 1, 0, memo) + targetCount - count[i] - min(targetCount - count[i], deletedCount));
    }

public:
    int makeStringGood(string &s) {
        vector<int> count(26);
        for (char c : s)
            count[c - 'a']++;
        
        int maxCount = *max_element(count.begin(), count.end()), res = 1e9;
        vector<vector<int>> memo;
        for (int targetCount = 0; targetCount <= maxCount; targetCount++) {
            memo.assign(count.size(), vector<int>(maxCount + 1, -1));
            res = min(res, rec(count, targetCount, 0, 0, memo));
        }
        return res;
    }
};