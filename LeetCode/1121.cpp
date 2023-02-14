class Solution {
public:
    bool canDivideIntoSubsequences(vector<int> &a, int k) {
        unordered_map<int, int> count;
        int maxCount = 0;
        for (int value : a)
            maxCount = max(maxCount, ++count[value]);
        return maxCount * k <= a.size();
    }
};