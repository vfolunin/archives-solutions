class Solution {
public:
    int longestSubsequence(vector<int> &a, int diff) {
        if (!diff) {
            unordered_map<int, int> count;
            int maxCount = 0;
            
            for (int value : a)
                maxCount = max(maxCount, ++count[value]);
            
            return maxCount;
        }
        
        unordered_map<int, int> length;
        int res = 0;
        
        for (int value : a) {
            length[value] = max(length[value], 1);
            if (length.count(value - diff))
                length[value] = max(length[value], length[value - diff] + 1);
            res = max(res, length[value]);
        }
        
        return res;
    }
};