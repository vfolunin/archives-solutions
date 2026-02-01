class Solution {
    int getLisSize(vector<int> &a, int bit) {
        vector<int> lisLast(a.size() + 1, 2e9);
        lisLast[0] = -2e9;
        
        for (int value : a)
            if (value & (1 << bit))
                *lower_bound(lisLast.begin(), lisLast.end(), value) = value;

        int lisSize = a.size();
        while (lisLast[lisSize] == 2e9)
            lisSize--;
        return lisSize;
    }

public:
    int longestSubsequence(vector<int> &a) {
        int res = 0;
        for (int bit = 0; bit < 30; bit++)
            res = max(res, getLisSize(a, bit));
        return res;
    }
};