class Solution {
    vector<int> getCount(string &word, string &letters) {
        vector<int> count(letters.size());
        for (char c : word)
            if (auto i = letters.find(c); i != -1)
                count[i]++;
        return count;
    }
    
    int rec(vector<int> &targetCount, vector<vector<int>> &counts, map<vector<int>, int> &memo) {
        if (memo.count(targetCount))
            return memo[targetCount];
        
        int &res = memo[targetCount];
        if (!*max_element(targetCount.begin(), targetCount.end()))
            return res;

        res = 1e9;
        for (vector<int> &count : counts) {
            vector<int> nextCount(targetCount.size());
            for (int i = 0; i < count.size(); i++)
                nextCount[i] = max(0, targetCount[i] - count[i]);
            res = min(res, 1 + rec(nextCount, counts, memo));
        }
        return res;
    }
    
public:
    int minStickers(vector<string> &words, string &target) {
        string letters = target;
        sort(letters.begin(), letters.end());
        letters.erase(unique(letters.begin(), letters.end()), letters.end());
    
        vector<int> targetCount = getCount(target, letters);
        
        vector<vector<int>> counts(words.size());
        for (int i = 0; i < counts.size(); i++)
            counts[i] = getCount(words[i], letters);
        
        map<vector<int>, int> memo;
        
        int res = rec(targetCount, counts, memo);
        
        return res != 1e9 ? res : -1;
    }
};