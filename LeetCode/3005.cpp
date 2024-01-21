class Solution {
public:
    int maxFrequencyElements(vector<int> &a) {
        unordered_map<int, int> count;
        int maxCount = 0;
        for (int value : a)
            maxCount = max(maxCount, ++count[value]);
        
        int res = 0;
        for (auto &[value, count] : count)
            if (count == maxCount)
                res += count;
        return res;
    }
};