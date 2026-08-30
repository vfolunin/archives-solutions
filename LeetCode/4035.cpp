class Solution {
    int getSplitCount(vector<int> a, int erasedIndex) {
        if (erasedIndex != -1)
            a.erase(a.begin() + erasedIndex);
        
        vector<int> l = a;
        for (int i = 1; i < a.size(); i++)
            l[i] = gcd(l[i - 1], a[i]);
            
        vector<int> r = a;
        for (int i = (int)a.size() - 2; i >= 0; i--)
            r[i] = gcd(a[i], r[i + 1]);
        
        int splitCount = 0;
        for (int i = 0; i + 1 < a.size(); i++)
            splitCount += l[i] == r[i + 1];
        return splitCount;
    }

public:
    int maxValidSplits(vector<int> &a) {
        int maxSplitCount = getSplitCount(a, -1);
        for (int i = 0; i < a.size(); i++)
            maxSplitCount = max(maxSplitCount, getSplitCount(a, i));
        return maxSplitCount;
    }
};