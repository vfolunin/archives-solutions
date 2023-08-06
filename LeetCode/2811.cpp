class Solution {
public:
    bool canSplitArray(vector<int> &a, int limit) {
        if (a.size() <= 2)
            return 1;
        
        for (int i = 0; i + 1 < a.size(); i++)
            if (a[i] + a[i + 1] >= limit)
                return 1;
        
        return 0;
    }
};