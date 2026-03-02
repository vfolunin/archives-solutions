class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int> &a) {
        map<int, int> count;
        for (int value : a)
            count[value]++;
        
        for (auto &[l, lCount] : count)
            for (auto &[r, rCount] : count)
                if (l < r && lCount != rCount)
                    return { l, r };
        return { -1, -1 };
    }
};